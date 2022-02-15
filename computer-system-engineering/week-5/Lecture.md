# Lecture 8 - Introduction to Networking

- What is a network
- A graph where leaf nodes are an endpoint (e.g. end user) and switch nodes
- Naming and addressing: assigning unique names (or addresses -- names imbued with location information) to nodes
- Routing: each node learns a (min-cost) route to every other reachable node
- Essentially: A weighted graph where the edges have weights associated with distance / speed, etc that is used to determine the fastest route
- Transport: sharing the network efficiently and fairly, dealing with reliability and differing application needs, etc

- Development of networks over time:
  - 1978: flexibility and layering
  - Early 80s: growth -> change
  - Early 90s: growth -> problems
  - 1993: commercialization (Internet / world wide web)

- Internet's design informs the problems we deal with today and how to deal with them
- Internet was designed to be flexible and robust to failure
- Commercialization of the internet has hindered flexibility
- Designing protocols or applications for Internet, must work within constraints of early design decisions
- Recurring themes: layering, hierarchy, scalability, performance and efficiency, diversity of applications, economics, end-to-end

# Lecture 9 - Link-state Routing and Distance-vector Routing

- Internet of problems
  - How do we route and address with scale and deal with issues of policy and economy?
  - How do we transport data with scale, while detailing with varying application demands?
  - How do we adapt new applications and technologies to an inflexible architecture?

- Goal of routing protocol: allow each switch to know, for every node `dst` in network, a minimum-cost route to `dst`
  - Routing table at each switch such that `routing_table[dst]` contains minimum-cost route to dst

- Distributed routing
  - Nodes learn about their neighbours via HELLO protocol
  - Nodes learn about other reachable nodes via advertisements
  - Nodes determine minimum-cost routes (of routes they know about)
- All steps happen periodically allowing for routing protocol to detect and respond to failures (e.g. node becomes unreachable therefore is not a valid path through the network anymore)

- Link-state routing
  - Disseminate topology information so that nodes can run shortest-path algorithm
  - Node's advertisements contain a list of neighbours and associated link costs to those nodes
  - Node sends advertisements to very other node with information about link cost (via flooding)

E.g. take following graph

- A -> B = 19
- A -> C = 7
- B -> C = 11
- B -> D = 4
- C -> D = 15
- C -> E = 5
- D -> E = 13

- A will advertise that its path to B costs 19 units while it's path to C costs 7 units
- Each node will continue advertising the link-cost of it's neighbours

- Since the advertisements are flooded, this type of routing performs well when there are failures but has overhead that limits the scale

- Distance-vector routing
  - Disseminate information about the current costs to each node, rather than actual topology
  - A node's advertisements contain list of all nodes it knows about and current costs to those nodes
  - Node sends advertisements only to its neighbours
  - Therefore, each node gets a list of costs from its neighbour

- Preventing looping: Never send routing information back in direction from which it was received

- Problem: neither distance-vector nor link-state routing will scale to size of Internet

## Summary

- Link-state routing works by disseminating full topology information to all nodes
  - Robust to failures but overhead of flooding limits scale
- Distance-vector routing works by disseminating information about cost of actual routes
  - Less overhead but not robust to failures
  - Handling failures limits scale
- Neither protocol is suitable for routing the entire Internet