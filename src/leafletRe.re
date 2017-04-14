module rec CRS: {type t;} = {
  type t;
}
and Layer: {type t;} = {
  type t;
}
and Point: {
  type t;
  let add: t => t => t;
  let subtract: t => t => t;
  let divideBy: t => float => t;
  let multiplyBy: t => float => t;
  let scaleBy: t => float => t;
  let unscaleBy: t => float => t;
  let distanceTo: t => t => float;
  let contains: t => t => bool;
  let equals: t => t => bool;
  let x: t => float;
  let y: t => float;
} = {
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
}
and LatLngBounds: {type t;} = {
  type t;
}
and LatLng: {
  type t;
  let lat: t => float;
  let lng: t => float;
  let alt: t => int;
  let toString: t => string;
  let equals: t => t => bool;
  let distanceTo: t => t => float;
  let wrap: t => t;
  let toBounds: int => t => LatLngBounds.t;
} = {
  type t;
  external lat : t => float = "" [@@bs.get];
  external lng : t => float = "" [@@bs.get];
  external alt : t => int = "" [@@bs.get];
  external toString : string = "" [@@bs.send.pipe : t];
  external equals : t => t => bool = "" [@@bs.send];
  external distanceTo : t => t => float = "" [@@bs.send];
  external wrap : t = "" [@@bs.send.pipe : t];
  external toBounds : int => LatLngBounds.t = "" [@@bs.send.pipe : t];
}
and Map: {
  type t;
  let crs: t => CRS.t;
  let center: t => option LatLng.t;
  let zoom: t => option int;
  let maxZoom: t => option int;
  let minZoom: t => option int;
  let layers: t => list Layer.t;
  let maxBounds: t => option LatLngBounds.t;
  /* Methods for Layers and Controls */
  let addLayer: t => Layer.t => t;
  let removeLayer: t => Layer.t => t;
  let hasLayer: t => Layer.t => bool;
} = {
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
}
and Control: {type t;} = {
  type t;
};

type map_options = Js.t {. center : (int, int), zoom : int};

type tile_layer_options = Js.t {. minZoom : int, maxZoom : int, detectRetina : bool};

external tileLayer : string => tile_layer_options => Layer.t = "" [@@bs.send];

external latLngBounds : LatLng.t => LatLng.t => LatLngBounds.t = "" [@@bs.send];

external latLng : (float, float) => LatLng.t = "" [@@bs.send];

external latLngAlt : (float, float, float) => LatLng.t = "latLng" [@@bs.send];

let create_lat_lng ::latitude ::longitude ::altitude =>
  switch altitude {
  | Some alt => latLngAlt (latitude, longitude, alt)
  | _ => latLng (latitude, longitude)
  };

external point : int => int => Point.t = "" [@@bs.send];

external point_float : float => float => Js.boolean => Point.t = "float" [@@bs.send];

external create_map : string => map_options => Map.t = "map" [@@bs.send];
