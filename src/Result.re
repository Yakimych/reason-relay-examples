module ResultFragment = [%relay.fragment
  {|
    fragment Result on results {
      id
      player1 {
        name
      }
      player1goals
      player2 {
        name
      }
      player2goals
      community {
        name
      }
    }
  |}
];

[@react.component]
let make = (~result, ~rating: int) => {
  let result = ResultFragment.use(result);
  <div key={result.id}>
    <span className="ratingcol">
      {React.string(rating |> string_of_int)}
    </span>
    <span className="playercol"> {React.string(result.player1.name)} </span>
    <span className="goalscol">
      {React.string(result.player1goals |> string_of_int)}
    </span>
    <span> {React.string(" - ")} </span>
    <span className="goalscol">
      {React.string(result.player2goals |> string_of_int)}
    </span>
    <span className="playercol"> {React.string(result.player2.name)} </span>
  </div>;
};
