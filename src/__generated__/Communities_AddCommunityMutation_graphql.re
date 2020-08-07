/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_insert_communities_one = {
    id: string,
    name: string,
  };

  type response = {
    insert_communities_one: option(response_insert_communities_one),
  };
  type rawResponse = response;
  type variables = {communityName: string};
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_communities_one":{"n":""}}} |json}
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
    {json| {"__root":{"insert_communities_one":{"n":""}}} |json}
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
  let makeVariables = (~communityName): variables => {
    communityName: communityName,
  };

  let make_response_insert_communities_one =
      (~id, ~name): response_insert_communities_one => {
    id,
    name,
  };

  let makeOptimisticResponse = (~insert_communities_one=?, ()): rawResponse => {
    insert_communities_one: insert_communities_one,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "communityName"
  }
],
v1 = [
  {
    "alias": null,
    "args": [
      {
        "fields": [
          {
            "kind": "Variable",
            "name": "name",
            "variableName": "communityName"
          }
        ],
        "kind": "ObjectValue",
        "name": "object"
      }
    ],
    "concreteType": "communities",
    "kind": "LinkedField",
    "name": "insert_communities_one",
    "plural": false,
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
        "kind": "ScalarField",
        "name": "name",
        "storageKey": null
      }
    ],
    "storageKey": null
  }
];
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "Communities_AddCommunityMutation",
    "selections": (v1/*: any*/),
    "type": "mutation_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Operation",
    "name": "Communities_AddCommunityMutation",
    "selections": (v1/*: any*/)
  },
  "params": {
    "cacheID": "aba039d770f83affd32ca04de13ab637",
    "id": null,
    "metadata": {},
    "name": "Communities_AddCommunityMutation",
    "operationKind": "mutation",
    "text": "mutation Communities_AddCommunityMutation(\n  $communityName: String!\n) {\n  insert_communities_one(object: {name: $communityName}) {\n    id\n    name\n  }\n}\n"
  }
};
})() |json}
];
