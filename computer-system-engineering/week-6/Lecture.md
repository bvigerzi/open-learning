# Lecture 10 - Scalable Routing, Policy Routing, BGP

## Internet of Problems

- How to route and address scalably while dealing with issues of policy and economy?
  - BGP
- How do we transport data scalably while dealing with varying application demands?
- How do we adapt new applications and technologies to an inflexible architecture?

## Distributed Routing

1. Node learn about neighbours via HELLO protocol
2. Nodes learn about reachable nodes via advertisements
3. Nodes determine min-cost routes for routes they know about via 2 steps above

- Problem: Neither distance-vector nor link-state routing can scale to the Internet

## Scalable Routing

1. Path-vector routing: advertisements include path -- better detect routing loops
2. Hierarchy of routing: route between autonomous systems, and then with an autonomous system
3. Topological addressing: assign addresses in contiguous blocks to make advertisements smaller

## Common Autonomous Systems Relationships

- Customer/provider ("transit")
  - Customer pays provider for transit
- Peers
  - Peers allow free mutual access to each other's customers

## Export Policies

- Customer/provider
  - Provider informs everyone about themselves and tell their customers about everyone
- Peers
  - Peers tell each other about their customers

## Import Policies

- customer > peer > provider
- Variety of other attributes when this relationship does not suffice

## BGP

- Border Gateway Protocol
  - Manages routing between autonomous systems (on the border of each system)

- Routing on Internet means to route at enormous scale
  - Path-vector routing
  - Hierarchy of routing
  - Topological addressing
- BGP provides means for autonomous systems to do policy routing
  - Protocol is simple but is complex due to competing economic interests
  - Concern as Internet continues to grow that BGP won't continue to scale

## Lecture 11 - Reliable Transport, Window-based Congestion Control

## Recap

- How do we route and address scalably, while dealing with issues of policy and economy? -> BGP
- How do we transport data scalably, while dealing with varying application demands? -> TCP
- How do we adapt new applications and technologies to an inflexible architecture?

## Reliable Transport

- The sending application may use a reliable sender and the receiving application may use a reliable receiver, but the network is unreliable
  - Each byte of data is delivered exactly once and in-order on receiving end

## Window-based Congestion Control

- Send multiple times, if there is a timeout some will likely get through
- If window is too small then the network is underutilised
- If the window is too large then we end up with network congestion
- How can a single reliable sender using a sliding-window protocol, set a window size to maximise utilisation? It must also prevent congestion and ensure network usage is fair
  - AIMD: Additive Increase Multiplicative Decrease

- Efficiency is when we consider sender rate 1 (R1) and sender rate 2 (R2) on an Y and X axis with a diagonal line drawn through the middle
  - Below the line is under-utilised network
  - Above the line is congestion
  - i.e. the bottleneck link (smallest link) is fully utilised when its capacity is consumed
  - B = R1 + R2
- Fairness is when R1 and R2 are equal (i.e. sender 1 and sender 2 can both send at the same rate)
  - R1 = R2
- Therefore, we have to solve for B = R1 + R2, R1 = R2, hence R1,R2 = B/2
- AIMD attempts to have a feedback loop that will try to get the rates to center around this point
  - When the size of the window is too small, it will additively increase (factor of 1)
  - When the size of the window is too big, it will decrease by multiple factors (factor of X)
  - Eventually the rates will oscillate around the solution B/2 and oscillate between slightly under-utilised and slightly congested

## Summary

- TCP provides reliable transport along with congestion control
  - Sender increase window additively until they experience loss and back off multiplicatively
  - Sender can use slow-start as well as fast-retransmit/fact-recovery to increase window and recover from loss
- TCP is a massive success (used a lot over the Internet)
  - Downside: senders do not react to congestion until queues are already full; maybe there is a better way?