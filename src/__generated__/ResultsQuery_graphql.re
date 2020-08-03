/* @generated */

module Types = {
  type response_results_connection_edges_node_community = {name: string};
  type response_results_connection_edges_node_player2 = {name: string};
  type response_results_connection_edges_node_player1 = {name: string};
  type response_results_connection_edges_node = {
    id: string,
    player1: response_results_connection_edges_node_player1,
    player1goals: int,
    player2: response_results_connection_edges_node_player2,
    player2goals: int,
    community: response_results_connection_edges_node_community,
  };
  type response_results_connection_edges = {
    node: response_results_connection_edges_node,
  };
  type response_results_connection = {
    edges: array(response_results_connection_edges),
  };

  type response = {results_connection: response_results_connection};
  type rawResponse = response;
  type variables = unit;
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

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

type queryRef;

module Utils = {};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "Literal",
    "name": "where",
    "value": {
      "community": {
        "name": {
          "_eq": "test"
        }
      }
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
    "name": "ResultsQuery",
    "selections": [
      {
        "alias": null,
        "args": (v0/*: any*/),
        "concreteType": "resultsConnection",
        "kind": "LinkedField",
        "name": "results_connection",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "resultsEdge",
            "kind": "LinkedField",
            "name": "edges",
            "plural": true,
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "results",
                "kind": "LinkedField",
                "name": "node",
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
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": "results_connection(where:{\"community\":{\"name\":{\"_eq\":\"test\"}}})"
      }
    ],
    "type": "query_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [],
    "kind": "Operation",
    "name": "ResultsQuery",
    "selections": [
      {
        "alias": null,
        "args": (v0/*: any*/),
        "concreteType": "resultsConnection",
        "kind": "LinkedField",
        "name": "results_connection",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "resultsEdge",
            "kind": "LinkedField",
            "name": "edges",
            "plural": true,
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "results",
                "kind": "LinkedField",
                "name": "node",
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
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": "results_connection(where:{\"community\":{\"name\":{\"_eq\":\"test\"}}})"
      }
    ]
  },
  "params": {
    "cacheID": "7c05dcd9ab0740c3843af5dcb2a015a3",
    "id": null,
    "metadata": {},
    "name": "ResultsQuery",
    "operationKind": "query",
    "text": "query ResultsQuery {\n  results_connection(where: {community: {name: {_eq: \"test\"}}}) {\n    edges {\n      node {\n        id\n        player1 {\n          name\n          id\n        }\n        player1goals\n        player2 {\n          name\n          id\n        }\n        player2goals\n        community {\n          name\n          id\n        }\n      }\n    }\n  }\n}\n"
  }
};
})() |json}
];

include ReasonRelay.MakeLoadQuery({
  type variables = Types.variables;
  type loadedQueryRef = queryRef;
  type response = Types.response;
  let query = node;
  let convertVariables = Internal.convertVariables;
});
