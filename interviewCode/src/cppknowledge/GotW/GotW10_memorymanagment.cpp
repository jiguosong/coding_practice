/*
 * GotW10_memorymanagment.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

/*
The following summarizes a C++ program's major distinct memory
areas. Note that some of the names (e.g., "heap") do not appear as
such in the draft [standard].

 Memory Area     Characteristics and Object Lifetimes
 --------------  ------------------------------------------------

 Const Data      The const data area stores string literals and
                 other data whose values are known at compile
                 time.  No objects of class type can exist in
                 this area.  All data in this area is available
                 during the entire lifetime of the program.

                 Further, all of this data is read-only, and the
                 results of trying to modify it are undefined.
                 This is in part because even the underlying
                 storage format is subject to arbitrary
                 optimization by the implementation.  For
                 example, a particular compiler may store string
                 literals in overlapping objects if it wants to.


 Stack           The stack stores automatic variables. Typically
                 allocation is much faster than for dynamic
                 storage (heap or free store) because a memory
                 allocation involves only pointer increment
                 rather than more complex management.  Objects
                 are constructed immediately after memory is
                 allocated and destroyed immediately before
                 memory is deallocated, so there is no
                 opportunity for programmers to directly
                 manipulate allocated but uninitialized stack
                 space (barring willful tampering using explicit
                 dtors and placement new).


 Free Store      The free store is one of the two dynamic memory
                 areas, allocated/freed by new/delete.  Object
                 lifetime can be less than the time the storage
                 is allocated; that is, free store objects can
                 have memory allocated without being immediately
                 initialized, and can be destroyed without the
                 memory being immediately deallocated.  During
                 the period when the storage is allocated but
                 outside the object's lifetime, the storage may
                 be accessed and manipulated through a void* but
                 none of the proto-object's nonstatic members or
                 member functions may be accessed, have their
                 addresses taken, or be otherwise manipulated.


 Heap            The heap is the other dynamic memory area,
                 allocated/freed by malloc/free and their
                 variants.  Note that while the default global
                 new and delete might be implemented in terms of
                 malloc and free by a particular compiler, the
                 heap is not the same as free store and memory
                 allocated in one area cannot be safely
                 deallocated in the other. Memory allocated from
                 the heap can be used for objects of class type
                 by placement-new construction and explicit
                 destruction.  If so used, the notes about free
                 store object lifetime apply similarly here.


 Global/Static   Global or static variables and objects have
                 their storage allocated at program startup, but
                 may not be initialized until after the program
                 has begun executing.  For instance, a static
                 variable in a function is initialized only the
                 first time program execution passes through its
                 definition.  The order of initialization of
                 global variables across translation units is not
                 defined, and special care is needed to manage
                 dependencies between global objects (including
                 class statics).  As always, uninitialized proto-
                 objects' storage may be accessed and manipulated
                 through a void* but no nonstatic members or
                 member functions may be used or referenced
                 outside the object's actual lifetime.

Note about Heap vs. Free Store: We distinguish between "heap" and
"free store" because the draft deliberately leaves unspecified the
question of whether these two areas are related. For example, when
memory is deallocated via operator delete, 18.4.1.1 states:

    It is unspecified under what conditions part or all of such
    reclaimed storage is allocated by a subsequent call to operator
    new or any of calloc, malloc, or realloc, declared in <cstdlib>.

Similarly, it is unspecified whether new/delete is implemented in
terms of malloc/free or vice versa in a given
implementation. Effectively, the two areas behave differently and are
accessed differently -- so be sure to use them differently!

*/
