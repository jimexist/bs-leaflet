open Jest;

open LeafletRe;

describe
  "point"
  (
    fun () => test "creation" (fun () => Just (Equal true (point 0 0 |> Point.equals (point 0 0))))
  );
