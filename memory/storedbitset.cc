#include "storedbitset.h"

StoredBitSet::StoredBitSet(Environment& __env, size_t __size) : StoredElement(__env) , _size(__size)
{
  for (size_t __i = 0 ; __i < (__size / _BITS_PER_WORD)+1 ; __i++)
    _words.push_back(new StoredLong(__env,0xffffffffffffffffLL));
}
StoredBitSet::~StoredBitSet()
{
  for (size_t __i = 0 ; __i < _words.size() ; __i++)
    delete _words[__i];
  std::cout << "Destructor sbitset called" << std::endl;
}

void StoredBitSet::set(size_t __elem)
{
  if (__elem < _size)
  {  
    size_t __widx = __elem >> _ADDR_BITS_PER_WORD;
    size_t __bidx = __elem - (__widx * _BITS_PER_WORD);
    
    _words[__widx]->set(_words[__widx]->get() | (1LL << __bidx));
  }
}

void StoredBitSet::clear(size_t __elem)
{
  if (__elem < _size)
  {
    size_t __widx = __elem >> _ADDR_BITS_PER_WORD;
    size_t __bidx = __elem - (__widx * _BITS_PER_WORD);
    
    _words[__widx]->set(_words[__widx]->get() & ~(1LL << __bidx));
  }
}

bool StoredBitSet::get(size_t __elem)
{
  if (__elem < _size)
  {
    size_t __widx = __elem >> _ADDR_BITS_PER_WORD;
    size_t __bidx = __elem - (__widx * _BITS_PER_WORD);
    return (_words[__widx]->get() & (1LL << __bidx)) != 0;
  }
  return 0;
}

int StoredBitSet::next_set(size_t __idx) {

  //++__elem;
  size_t __widx = __idx >> _ADDR_BITS_PER_WORD;
  
  if (__widx >= _words.size())
      return -1;

  uint64_t word = _words[__widx]->get() & (_WORD_MASK << __idx);

  while (true) 
  {
    if (word != 0)
      return (__widx * _BITS_PER_WORD) + __builtin_ctzll(word);
    if (++__widx == _words.size())
      return -1;
    word = _words[__widx]->get();
    }
} 

int StoredBitSet::prev_set(size_t __idx) {

  size_t __widx = __idx >> _ADDR_BITS_PER_WORD;
  
  if ( __widx >= _words.size())
    return -1;

  uint64_t mask = (_WORD_MASK << __idx + 1) ^ _WORD_MASK;
  uint64_t word = _words[__widx]->get() & ( mask != 0 ? mask : _WORD_MASK );


  while (true) 
  {
    if (word != 0)
      return (__widx * _BITS_PER_WORD) + _BIT_INDEX_MASK - __builtin_clzll(word);
    if (__widx-- == 0)
      return -1;
    word = _words[__widx]->get();
  }
}

int StoredBitSet::prev_clear(size_t __idx) 
{
  size_t __widx = __idx >> _ADDR_BITS_PER_WORD;

  if ( __widx >= _words.size())
    return -1;
        

  uint64_t mask = (_WORD_MASK << __idx + 1) ^ _WORD_MASK;
  uint64_t word = ~_words[__widx]->get() & ( mask != 0 ? mask : _WORD_MASK );

  while (true) 
  {
    if (word != 0)
      return (__widx * _BITS_PER_WORD) + _BIT_INDEX_MASK - __builtin_clzll(word);
    if (__widx-- == 0)
      return -1;
    word = ~_words[__widx]->get();
  }
}

int StoredBitSet::next_clear(size_t __idx) {
  
  size_t __widx = __idx >> _ADDR_BITS_PER_WORD;

  if ( __widx >= _words.size())
    return -1;
    
  uint64_t word = ~_words[__widx]->get() & (_WORD_MASK << __idx);

    while (true) {
        if (word != 0)
            return (__widx * _BITS_PER_WORD) + __builtin_ctzll(word);
        if (++__widx ==_words.size())
            return-1;
        word = ~_words[__widx]->get();
    }
}
      

void StoredBitSet::print()
{
  unsigned int c = 0;
  for (size_t i = 0 ; i < _words.size() ;i++)
  {
    for (int j = 0 ; j < _BITS_PER_WORD ; j++)
    {
      std::cout << (get(i*_BITS_PER_WORD+j));
      c++;
      if (c == _size) break;
      }
  }
  std::cout << std::endl;
}