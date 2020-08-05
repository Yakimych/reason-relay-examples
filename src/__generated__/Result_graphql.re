/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_player1 = {name: string}
  and fragment_player2 = {name: string}
  and fragment_community = {name: string};

  type fragment = {
    id: string,
    player1: fragment_player1,
    player1goals: int,
    player2: fragment_player2,
    player2goals: int,
    community: fragment_community,
  };
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
external getFragmentRef:
  ReasonRelay.fragmentRefs([> | `Result]) => fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "alias": null,
    "args": null,
    "kind": "ScalarField",
    "name": "name",
    "storageKey": null
  }
];
return {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Result",
  "selections": [
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "id",
      "storageKey": null
    },
    {
      "alias": null,
      "args": null,
      "concreteType": "players",
      "kind": "LinkedField",
      "name": "player1",
      "plural": false,
      "selections": (v0/*: any*/),
      "storageKey": null
    },
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "player1goals",
      "storageKey": null
    },
    {
      "alias": null,
      "args": null,
      "concreteType": "players",
      "kind": "LinkedField",
      "name": "player2",
      "plural": false,
      "selections": (v0/*: any*/),
      "storageKey": null
    },
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "player2goals",
      "storageKey": null
    },
    {
      "alias": null,
      "args": null,
      "concreteType": "communities",
      "kind": "LinkedField",
      "name": "community",
      "plural": false,
      "selections": (v0/*: any*/),
      "storageKey": null
    }
  ],
  "type": "results",
  "abstractKey": null
};
})() |json}
];
