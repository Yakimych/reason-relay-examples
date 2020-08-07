module CommunityFragment = [%relay.fragment
  {|
    fragment Community on communities {
      id
      name
    }
  |}
];

[@react.component]
let make = (~community) => {
  let community = CommunityFragment.use(community);
  <div key={community.id}>
    <span className="communitycol"> {React.string(community.name)} </span>
    <span className="communityidcol"> {React.string(community.id)} </span>
  </div>;
};
