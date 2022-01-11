# Lecture 1

## Systems

- What is a system? interconnected components that has expected behaviour observed at interface with its environment
- What makes building them difficult? The complexity of the components and the way they interconnect
- Complexity is a limiting factor - it limits WHAT we can build and causes hidden issues
- Therefore; we need to reduce the complexity as much as possible
  - Design principles;
    - Modularity
    - Abstraction

### Modularity

- Enforce using client/server model
  - Client makes request to server which is it's own sub-system as part of the entire client/server system
  - This becomes a Remote Procedure Call (RPC) where the client calls a procedure on the server remotely
    - Challenge: Internet can be flakey -- what if the response is never received?
      - Retry?
      - What about requests that need to be idempotent? E.g. buying an item online -- cannot be retried otherwise the server will think we have bought the same item twice
      - Solution: include a unique ID in the request; the server can lookup the UID to see if it has seen it before; if so the server will just respond without re-purchasing the item
    - Challenge: Scaling to multiple (several dozen/hundreds/thousands/10s of thousands) clients
    - Challenge: Having fault-tolerance and reliability of your product
      - What if a server is unavailable?
      - What if a client fails?
    - Challenge: Security of the system (client and server side)

## Summary

- Complexity limits what can be built
  - Mitigated using modularity and abstractions
- Client/server model enforces modularity -- client sends RPC to server where functionality is modularised between the two
  - Client can be simple, server can become complex
  - Issue with network and server failures can add to complexity -- need to be able to handle these error conditions