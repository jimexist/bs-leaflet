open Jest;

describe(
  "latLng",
  LeafletRe.(
    () =>
      test(
        "creation",
        LatLng.(
          () =>
            Just(
              Equal(
                true,
                equals(
                  create_lat_lng(~latitude=0., ~longitude=0., ~altitude=None),
                  create_lat_lng(~latitude=0., ~longitude=0., ~altitude=None)
                )
              )
            )
        )
      )
  )
);

describe(
  "point",
  LeafletRe.(
    () => {
      test(
        "creation",
        Point.(() => Just(Equal(true, point_int(0, 0) |> equals(point_int(0, 0)))))
      );
      test(
        "creation float",
        Point.(
          () =>
            Just(
              Equal(true, point_float(0., 0., Js.false_) |> equals(point_float(0., 0., Js.false_)))
            )
        )
      );
      test(
        "creation float with rounding",
        Point.(
          () =>
            Just(
              Equal(
                true,
                point_float(0.1, 0.1, Js.true_) |> equals(point_float(0.2, 0.2, Js.true_))
              )
            )
        )
      )
    }
  )
);
