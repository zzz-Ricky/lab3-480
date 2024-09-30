// LookupTable.h
// ENSF 480 - Lab 3, Ex C

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node.

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.

// Forward Declaration
template <typename LT_Key, typename LT_Datum>
class LookupTable; // Forward declaration

template <typename LT_Key = int, typename LT_Datum = Customer>
struct Pair
{
  Pair(LT_Key keyA, LT_Datum datumA) : key(keyA), datum(datumA)
  {
  }

  LT_Key key;
  LT_Datum datum;
};

template <typename LT_Key = int, typename LT_Datum = Customer>
class LT_Node
{
  friend class LookupTable<LT_Key, LT_Datum>;

private:
  Pair<LT_Key, LT_Datum> pairM;
  LT_Node *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<LT_Key, LT_Datum> &pairA, LT_Node *nextA);
};

template <typename LT_Key = int, typename LT_Datum = Customer>
class LookupTable
{
public:
  // Nested class
  class Iterator
  {
    friend class LookupTable<LT_Key, LT_Datum>;
    LookupTable<LT_Key, LT_Datum> *LT;
    //    LT_Node* cursor;

  public:
    Iterator() : LT(0) {}
    Iterator(LookupTable<LT_Key, LT_Datum> &x) : LT(&x) {}
    const LT_Datum &operator*();
    const LT_Datum &operator++();
    const LT_Datum &operator++(int);
    int operator!();

    void step_fwd()
    {
      assert(LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable();
  LookupTable(const LookupTable &source);
  LookupTable &operator=(const LookupTable &rhs);
  ~LookupTable();

  LookupTable &begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES:
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const LT_Key &cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const LT_Datum &cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair<LT_Key, LT_Datum> &pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const LT_Key &keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const LT_Key &keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES:
  //   If cursor is at the last key/datum pair in the list, cursor
  //   goes to the off-list state.
  //   Otherwise the cursor moves forward from one pair to the next.

  void make_empty();
  // PROMISES: size() == 0.

  template <typename K, typename D>
  friend ostream &operator<<(ostream &os, const LookupTable<K, D> &lt);

private:
  int sizeM;
  LT_Node<LT_Key, LT_Datum> *headM;
  LT_Node<LT_Key, LT_Datum> *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.

  void copy(const LookupTable<LT_Key, LT_Datum> &source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template <typename LT_Key, typename LT_Datum>
LookupTable<LT_Key, LT_Datum> &LookupTable<LT_Key, LT_Datum>::begin()
{
  cursorM = headM;
  return *this;
}

template <typename LT_Key, typename LT_Datum>
LT_Node<LT_Key, LT_Datum>::LT_Node(const Pair<LT_Key, LT_Datum> &pairA, LT_Node *nextA)
    : pairM(pairA), nextM(nextA)
{
}

template <typename LT_Key, typename LT_Datum>
LookupTable<LT_Key, LT_Datum>::LookupTable()
    : sizeM(0), headM(nullptr), cursorM(nullptr)
{
}

template <typename LT_Key, typename LT_Datum>
LookupTable<LT_Key, LT_Datum>::LookupTable(const LookupTable<LT_Key, LT_Datum> &source)
{
  copy(source);
}

template <typename LT_Key, typename LT_Datum>
LookupTable<LT_Key, LT_Datum> &LookupTable<LT_Key, LT_Datum>::operator=(const LookupTable<LT_Key, LT_Datum> &rhs)
{
  if (this != &rhs)
  {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <typename LT_Key, typename LT_Datum>
LookupTable<LT_Key, LT_Datum>::~LookupTable()
{
  destroy();
}

template <typename LT_Key, typename LT_Datum>
int LookupTable<LT_Key, LT_Datum>::size() const
{
  return sizeM;
}

template <typename LT_Key, typename LT_Datum>
int LookupTable<LT_Key, LT_Datum>::cursor_ok() const
{
  return cursorM != 0;
}

template <typename LT_Key, typename LT_Datum>
const LT_Key &LookupTable<LT_Key, LT_Datum>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <typename LT_Key, typename LT_Datum>
const LT_Datum &LookupTable<LT_Key, LT_Datum>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::insert(const Pair<LT_Key, LT_Datum> &pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key)
  {
    headM = new LT_Node<LT_Key, LT_Datum>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else
  {
    LT_Node<LT_Key, LT_Datum> *before = headM;
    LT_Node<LT_Key, LT_Datum> *after = headM->nextM;

    while (after != NULL && (pairA.key > after->pairM.key))
    {
      before = after;
      after = after->nextM;
    }

    if (after != NULL && pairA.key == after->pairM.key)
    {
      after->pairM.datum = pairA.datum;
    }
    else
    {
      before->nextM = new LT_Node<LT_Key, LT_Datum>(pairA, before->nextM);
      sizeM++;
    }
  }
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::remove(const LT_Key &keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<LT_Key, LT_Datum> *doomed_node = 0;
  if (keyA == headM->pairM.key)
  {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else
  {
    LT_Node<LT_Key, LT_Datum> *before = headM;
    LT_Node<LT_Key, LT_Datum> *maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->pairM.key)
    {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA)
    {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }
  }
  delete doomed_node; // Does nothing if doomed_node == 0.
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::find(const LT_Key &keyA)
{
  LT_Node<LT_Key, LT_Datum> *ptr = headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
  {
    ptr = ptr->nextM;
  }

  cursorM = ptr;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::go_to_first()
{
  cursorM = headM;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::destroy()
{

  LT_Node<LT_Key, LT_Datum> *ptr = headM;
  while (ptr != NULL)
  {
    headM = headM->nextM;
    delete ptr;
    ptr = headM;
  }
  cursorM = NULL;
  sizeM = 0;
}

template <typename LT_Key, typename LT_Datum>
void LookupTable<LT_Key, LT_Datum>::copy(const LookupTable<LT_Key, LT_Datum> &source)
{

  headM = 0;
  cursorM = 0;

  if (source.headM == 0)
    return;

  for (LT_Node<LT_Key, LT_Datum> *p = source.headM; p != 0; p = p->nextM)
  {
    insert(Pair<LT_Key, LT_Datum>(p->pairM.key, p->pairM.datum));
    if (source.cursorM == p)
      find(p->pairM.key);
  }
}

template <typename LT_Key = int, typename LT_Datum = Customer>
ostream &operator<<(ostream &os, const LookupTable<LT_Key, LT_Datum> &lt)
{
  if (lt.cursor_ok())
    os << lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os << "Not Found.";

  return os;
}

template <typename LT_Key = int, typename LT_Datum = Customer>
const LT_Datum &LookupTable<LT_Key, LT_Datum>::Iterator::operator*()
{
  assert(LT->cursor_ok());
  return LT->cursor_datum();
}

template <typename LT_Key = int, typename LT_Datum = Customer>
const LT_Datum &LookupTable<LT_Key, LT_Datum>::Iterator::operator++()
{
  assert(LT->cursor_ok());
  const LT_Datum &x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <typename LT_Key = int, typename LT_Datum = Customer>
const LT_Datum &LookupTable<LT_Key, LT_Datum>::Iterator::operator++(int)
{
  assert(LT->cursor_ok());

  LT->step_fwd();
  return LT->cursor_datum();
}

template <typename LT_Key = int, typename LT_Datum = Customer>
int LookupTable<LT_Key, LT_Datum>::Iterator::operator!()
{
  return (LT->cursor_ok());
}
