module CRS = {
  type t;
};

module Layer = {
  type t;
};

module Point = {
  type t;
  external add : t => t => t = "" [@@bs.send];
  external subtract : t => t => t = "" [@@bs.send];
  external divideBy : t => float => t = "" [@@bs.send];
  external multiplyBy : t => float => t = "" [@@bs.send];
  external scaleBy : t => float => t = "" [@@bs.send];
  external unscaleBy : t => float => t = "" [@@bs.send];
  external distanceTo : t => float = "" [@@bs.send.pipe : t];
  external contains : t => bool = "" [@@bs.send.pipe : t];
  external equals : t => bool = "" [@@bs.send.pipe : t];
  external x : t => float = "" [@@bs.get];
  external y : t => float = "" [@@bs.get];
};

module LatLngBounds = {
  type t;
};

module LatLng = {
  type t;
  external lat : t => float = "" [@@bs.get];
  external lng : t => float = "" [@@bs.get];
  external alt : t => int = "" [@@bs.get];
  external toString : string = "" [@@bs.send.pipe : t];
  external equals : t => t => bool = "" [@@bs.send];
  external distanceTo : t => t => float = "" [@@bs.send];
  external wrap : t = "" [@@bs.send.pipe : t];
  external toBounds : int => LatLngBounds.t = "" [@@bs.send.pipe : t];
};

module Map = {
  type t;
  /* Interaction Options */
  /* Map State Options */
  external crs : CRS.t = "" [@@bs.send.pipe : t];
  external center : option LatLng.t = "" [@@bs.send.pipe : t] [@@bs.return undefined_to_opt];
  external zoom : option int = "" [@@bs.send.pipe : t] [@@bs.return undefined_to_opt];
  external maxZoom : option int = "" [@@bs.send.pipe : t] [@@bs.return undefined_to_opt];
  external minZoom : option int = "" [@@bs.send.pipe : t] [@@bs.return undefined_to_opt];
  external layers : list Layer.t = "" [@@bs.send.pipe : t];
  external maxBounds : option LatLngBounds.t = "" [@@bs.send.pipe : t] [@@bs.return null_to_opt];
  /* Methods for Layers and Controls */
  external addLayer : t => Layer.t => t = "" [@@bs.send];
  external removeLayer : t => Layer.t => t = "" [@@bs.send];
  external hasLayer : t => Layer.t => bool = "" [@@bs.send];
};

module Control = {
  type t;
};

type map_options = Js.t {. center : (int, int), zoom : int};

type tile_layer_options = Js.t {. minZoom : int, maxZoom : int, detectRetina : bool};

external tileLayer : string => tile_layer_options => Layer.t = "" [@@bs.module "leaflet"];

external latLngBounds : LatLng.t => LatLng.t => LatLngBounds.t = "" [@@bs.module "leaflet"];

external latLng : (float, float) => LatLng.t = "" [@@bs.module "leaflet"];

external latLngAlt : (float, float, float) => LatLng.t = "latLng" [@@bs.module "leaflet"];

let create_lat_lng ::latitude ::longitude ::altitude =>
  switch altitude {
  | Some alt => latLngAlt (latitude, longitude, alt)
  | _ => latLng (latitude, longitude)
  };

external point_int : int => int => Point.t = "point" [@@bs.module "leaflet"];

external point_float : float => float => Js.boolean => Point.t = "point" [@@bs.module "leaflet"];

external create_map : string => map_options => Map.t = "map" [@@bs.module "leaflet"];
