Unit Testing Property Types
===========================

Conceptually each property type is an abstract base class. The actual
`PropertyType` class is unit tested in SDE and does not need to be tested here
again. What we need to test are the derived classes, which define the property
types modules can choose from. For the most part these derived classes do not
do anything aside from define meta data. Thus these unit tests do not do much
beyond asserting that the property types compile and are usable.
