/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_insert_results_one = {
    id: string,
    player1: response_insert_results_one_player1,
    player1goals: int,
    player2: response_insert_results_one_player2,
    player2goals: int,
    community: response_insert_results_one_community,
  }
  and response_insert_results_one_player1 = {name: string}
  and response_insert_results_one_player2 = {name: string}
  and response_insert_results_one_community = {name: string};

  type response = {insert_results_one: option(response_insert_results_one)};
  type rawResponse = response;
  type variables = unit;
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_results_one":{"n":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay._convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_results_one":{"n":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type wrapRawResponseRaw = wrapResponseRaw;
  let convertWrapRawResponse = convertWrapResponse;

  type rawResponseRaw = responseRaw;
  let convertRawResponse = convertResponse;

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

module Utils = {
  open Types;
  let make_response_insert_results_one_community =
      (~name): response_insert_results_one_community => {
    name: name,
  };

  let make_response_insert_results_one_player2 =
      (~name): response_insert_results_one_player2 => {
    name: name,
  };

  let make_response_insert_results_one_player1 =
      (~name): response_insert_results_one_player1 => {
    name: name,
  };

  let make_response_insert_results_one =
      (~id, ~player1, ~player1goals, ~player2, ~player2goals, ~community)
      : response_insert_results_one => {
    id,
    player1,
    player1goals,
    player2,
    player2goals,
    community,
  };

  let makeOptimisticResponse = (~insert_results_one=?, ()): rawResponse => {
    insert_results_one: insert_results_one,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "Literal",
    "name": "object",
    "value": {
      "community": {
        "data": {
          "name": "test2"
        },
        "on_conflict": {
          "constraint": "communities_name_key",
          "update_columns": "name"
        }
      },
      "date": "2020-01-01",
      "extratime": false,
      "player1Id": 203,
      "player1goals": 3,
      "player2Id": 208,
      "player2goals": 2
    }
  }
],
v1 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
},
v2 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "name",
  "storageKey": null
},
v3 = [
  (v2/*: any*/)
],
v4 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "player1goals",
  "storageKey": null
},
v5 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "player2goals",
  "storageKey": null
},
v6 = [
  (v2/*: any*/),
  (v1/*: any*/)
];
return {
  "fragment": {
    "argumentDefinitions": [],
    "kind": "Fragment",
    "metadata": null,
    "name": "Results_AddResultMutation",
    "selections": [
      {
        "alias": null,
        "args": (v0/*: any*/),
        "concreteType": "results",
        "kind": "LinkedField",
        "name": "insert_results_one",
        "plural": false,
        "selections": [
          (v1/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "players",
            "kind": "LinkedField",
            "name": "player1",
            "plural": false,
            "selections": (v3/*: any*/),
            "storageKey": null
          },
          (v4/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "players",
            "kind": "LinkedField",
            "name": "player2",
            "plural": false,
            "selections": (v3/*: any*/),
            "storageKey": null
          },
          (v5/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "communities",
            "kind": "LinkedField",
            "name": "community",
            "plural": false,
            "selections": (v3/*: any*/),
            "storageKey": null
          }
        ],
        "storageKey": "insert_results_one(object:{\"community\":{\"data\":{\"name\":\"test2\"},\"on_conflict\":{\"constraint\":\"communities_name_key\",\"update_columns\":\"name\"}},\"date\":\"2020-01-01\",\"extratime\":false,\"player1Id\":203,\"player1goals\":3,\"player2Id\":208,\"player2goals\":2})"
      }
    ],
    "type": "mutation_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [],
    "kind": "Operation",
    "name": "Results_AddResultMutation",
    "selections": [
      {
        "alias": null,
        "args": (v0/*: any*/),
        "concreteType": "results",
        "kind": "LinkedField",
        "name": "insert_results_one",
        "plural": false,
        "selections": [
          (v1/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "players",
            "kind": "LinkedField",
            "name": "player1",
            "plural": false,
            "selections": (v6/*: any*/),
            "storageKey": null
          },
          (v4/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "players",
            "kind": "LinkedField",
            "name": "player2",
            "plural": false,
            "selections": (v6/*: any*/),
            "storageKey": null
          },
          (v5/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "communities",
            "kind": "LinkedField",
            "name": "community",
            "plural": false,
            "selections": (v6/*: any*/),
            "storageKey": null
          }
        ],
        "storageKey": "insert_results_one(object:{\"community\":{\"data\":{\"name\":\"test2\"},\"on_conflict\":{\"constraint\":\"communities_name_key\",\"update_columns\":\"name\"}},\"date\":\"2020-01-01\",\"extratime\":false,\"player1Id\":203,\"player1goals\":3,\"player2Id\":208,\"player2goals\":2})"
      }
    ]
  },
  "params": {
    "cacheID": "aa61ff5bd10309f6384c685ef11b0c9a",
    "id": null,
    "metadata": {},
    "name": "Results_AddResultMutation",
    "operationKind": "mutation",
    "text": "mutation Results_AddResultMutation {\n  insert_results_one(object: {community: {data: {name: \"test2\"}, on_conflict: {constraint: communities_name_key, update_columns: name}}, player1Id: 203, player2Id: 208, player1goals: 3, player2goals: 2, date: \"2020-01-01\", extratime: false}) {\n    id\n    player1 {\n      name\n      id\n    }\n    player1goals\n    player2 {\n      name\n      id\n    }\n    player2goals\n    community {\n      name\n      id\n    }\n  }\n}\n"
  }
};
})() |json}
];
