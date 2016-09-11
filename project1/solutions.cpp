#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the 
// function-prototype to the solutions.hpp. The function-prototypes 
// for append and reverse are already in solutions.hpp.

list append( list p, list q )
{
    if( is_null( p ) ) return q;
    return cons( car(p), append( cdr(p), q ));
}

list reverse( list p )
{
    if( is_null(p) || is_atom(p) ) return p;
    return append( reverse( cdr(p) ), cons(car(p), null() )) ;
}

bool is_lat(list p)
{
	// Is the first element an atom?
	if (is_atom(car(p)))
	{
		// Is it the only elemnt?
		if (is_null(cdr(p)))
		{
			return true;
		}
		
		// If there are other elements, recurse!
		return is_lat(cdr(p));
	}
	
	// The first element isn't an atom!
	// List can't be made up of only atoms then.
	return false;
}

bool member (list p, list q)
{
	// Checks to make sure we are actually looking at atoms.
	if (!is_atom(p) || !is_atom(car(q)))
	{
		throw "Member preconditions not met";
	}
	
	// Is the first element of q p?
	if (eq(car(q), p))
	{
		return true;
	}
	else
	{
		// Does q only have one element
		if (is_null(cdr(p)))
		{
			return false;
		}
		
		// If there are other elements, recurse!
		return member(cdr(q));
	}
}

bool nonAtomicMember (list p, list q)
{
	// Is the first element of q p?
	if (equal(car(q), p))
	{
		return true;
	}
	else
	{
		// Does p only have one element
		if (is_null(cdr(p)))
		{
			return false;
		}
		
		// If there are other elements, recurse!
		return member(cdr(p));
	}
}

list deletepfromq (list p, list q)
{
	// If p is in q
	if (nonAtomicMember(p, q))
	{
		// If p is the first element of q
		if (equal(p, car(q)))
		{
			// Get em outa here!
			return cdr(q);
		}
		
		// Keep looking
		return cons(car(q), deletepfromq(p, cdr(q)));
	}
	
	if (is_null(cdr(q)))
	{
		return q;
	}
}

list last (list p)
{
	// Does p have only one element?
	if (is_null(cdr(p))
	{
		// Return the only element
		return car(p);
	}
	
	// If there are other elements, recurse!
	return last(cdr(p));
}

list list_pair (list p, list q)
{
	if (!is_atom(car(p)) || !is_atom(car(q)))
	{
		throw "Lists are not composed only of atoms";
	}
	
	// Does p have only one element?
	if (is_null(cdr(p))
	{
		// Return a list of the last elements of both lists
		return append(car(list p), car(list q));
	}
	
	// Append the first two elements of p and q
	// Append that with pairs from the rest of the elements
	return append(append(car(list p), car(list q)), list_par(cdr(p), cdr(q)));
}

list firsts (list p)
{
	// Does p have only one element?
	if (is_null(cdr(p))
	{
		// Return the only element
		return car(car(p));
	}
	
	// Return the first element of the first list
	// Appended to the first elements of the remaining lists
	return append(car(car(p)), firsts(cdr(p)));
}

list flat (list p)
{
	// If the list is an atom, just return that
	if (is_atom(p))
	{
		return p;
	}
	
	// If the first element is null, just recurse and ignore ir.
	if (is_null(car(p)))
	{
		return flat(cdr(p));
	}
	else
	{
		// Return the flattened first element with the flattend
		// remaining elements
		return append(flat(car(p)), flat(cdr(p)));
	}
}

bool two_the_same(list p, list q)
{
	// Looks for the first member of a flat version of p in a flat 
	// version of q
	if (member(car(flat(p)), flat(q)))
	{
		return true;
	}
	
	// Does p have only one element?
	// Well, we just looked and it wasn't in q, so no luck
	if (is_null(cdr(p))
	{
		// Nothing in p exists in q
		return false;
	}
	
	// Grab the elemnts of p we haven't searched for yet, and look for those
	return two_the_same(cdr(p), q);
}

bool equal (list p, list q)
{
	// If both lists are atoms, return whether they are equal
	if (is_atom(p) && is_atom(q))
	{
		return eq(p, q);
	}
	
	// If both are null, they equal, if one is, they are not.
	if(is_null(p))
	{
		if (is_null(q))
		{
			return true;
		}
		
		return false;
	}
	
	// Either p or q have only one element?
	if (is_null(cdr(p))
	{
		if (is_null(cdr(q))
		{
			// Check if that element is equal
			return equal(car(p), car(q));
		}
		
		// Lists are different lengths
		return false;
	}
	
	// Are the first elements of both lists equal?
	if (equal(car(p), car(q))) {
		// Then check the rest of the list
		return equal(cdr(p), cdr(q));
	}
}

list total_reverse(list p)
{
	// If we get an atom or null, just give it back.
	if (is_atom(p) || is_null(p))
		return p;
	
	// If the list is all atoms, reverse it.
	if( is_lat(p))
	{
		return reverse(p);
	}
	
	// Does p have only one element?
	if (is_null(cdr(p))
	{
		// Reverse the only element
		return total_reverse(car(p));
	}
	
	// Reverse all elements of p in place, and the reverse the whole list
	return reverse(append(total_reverse(car(p)), total_reverse(cdr(p))));
}

list shape(list p)
{
	// If p isn't a non-atomic list which isn't null or an atom, return null
	if (is_atom(p))
	{
		return null();
	}
	if (is_lat(p) || is_null(p))
	{
		return null();
	}
	
	// Does p have only one element?
	if (is_null(cdr(p))
	{
		// return it's shape
		return shape(car(p));
	}
	
	// Nest the results of our calls
	return cons(shape(car(p)), shape(cdr(p)));
}

list intersetction(list p, list q)
{
	// Does p have only one element?
	if (is_null(p)
	{
		// return p
		return p;
	}
	
	// If the first element of p is an element of q
	if (nonAtomicMember(car(p), q))
	{
		// Combine the first element with any others that match
		return cons(car(p), intersection(cdr(p)));  
	}
	else
	{
		// Keep looking
		return intersection(cdr(p));
	}
}

list list_union(list p, list q)
{
	
	// Does p have only one element?
	if (is_null(p))
	{
		// return p
		return p;
	}
	
	// If the first element of p isn't an element of q
	if (!nonAtomicMember(car(p), q))
	{
		// Keep it 
		return = cons(car(p), list_union(cdr(p), q));  
	}
	else
	{
		// Look at the next element of p
		return list_union(cdr(p), deletepfromq(car(p), q));
	}
}