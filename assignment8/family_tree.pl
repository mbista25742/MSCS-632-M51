% Basic Relationships
parent(john, mary).
parent(john, sam).
parent(linda, mary).
parent(linda, sam).

parent(mary, alice).
parent(mary, bob).
parent(paul, alice).
parent(paul, bob).

parent(sam, tom).
parent(susan, tom).

male(john).
male(sam).
male(paul).
male(bob).
male(tom).

female(linda).
female(mary).
female(susan).
female(alice).

% Derived Relationships

% Grandparent Rule
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Sibling Rule
sibling(X, Y) :- parent(P, X), parent(P, Y), X \= Y.

% Cousin Rule
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B), X \= Y.

% Children of a parent
child(X, Y) :- parent(Y, X).

% Recursive: Descendant
descendant(X, Y) :- parent(Y, X).
descendant(X, Y) :- parent(Z, X), descendant(Z, Y).
