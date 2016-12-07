#---------------------------------------------------------------------------------
# Vega Strike vector class
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# Description: A python vector class#
# Author: pyramid
# Version: 2008-09-13 | v0.25
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------
#---------------------------------------------------------------------------------
# Original python vector class
# A. Pletzer 5 Jan 00/11 April 2002
#---------------------------------------------------------------------------------
# Features:
#---------------------------------------------------------------------------------

import math

class vector(list):

  def __getslice__(self, i, j):
		try:
			# use the list __getslice__ method and convert
			# result to vector
			return vector(super(vector, self).__getslice__(i,j))
		except:
			raise TypeError, 'vector::FAILURE in __getslice__'

  def __add__(self, other):
		return vector(map(lambda x,y: x+y, self, other))

  def __neg__(self):
		return vector(map(lambda x: -x, self))

  def __sub__(self, other):
		return vector(map(lambda x,y: x-y, self, other))

  def __mul__(self, other):
  # Element by element multiplication
    try:
	    return vector(map(lambda x,y: x*y, self,other))
    except:
	    # other is a const
	    return vector(map(lambda x: x*other, self))

  def __rmul__(self, other):
		return (self*other)

  def __div__(self, other):
    """
    Element by element division.
    """
    try:
	    return vector(map(lambda x,y: x/y, self, other))
    except:
	    return vector(map(lambda x: x/other, self))

  def __rdiv__(self, other):
    """
    The same as __div__
    """
    try:
	    return vector(map(lambda x,y: x/y, other, self))
    except:
	    # other is a const
	    return vector(map(lambda x: other/x, self))

  def size(self):
      return len(self)

  def conjugate(self):
	    return vector(map(lambda x: x.conjugate(), self))

  def ReIm(self):
		"""
		Return the real and imaginary parts
		"""
		return [
			vector(map(lambda x: x.real, self)),
			vector(map(lambda x: x.imag, self)),
			]
	
  def AbsArg(self):
		"""
		Return modulus and phase parts
		"""
		return [
			vector(map(lambda x: abs(x), self)),
			vector(map(lambda x: math.atan2(x.imag,x.real), self)),
			]

  def out(self):
	    """
	    Prints out the vector.
	    """
	    print self

###############################################################################

def vlength(x):
# determines vector length
  return math.sqrt(dot(x,x))

def vnormal(x):
# determines vector length
  return x/vlength(x)

def isVector(x):
    """
    Determines if the argument is a vector class object.
    """
    return hasattr(x,'__class__') and x.__class__ is vector

def zeros(n):
    """
    Returns a zero vector of length n.
    """
    return vector(map(lambda x: 0., range(n)))

def ones(n):
    """
    Returns a vector of length n with all ones.
    """
    return vector(map(lambda x: 1., range(n)))

def random(n, lmin=0.0, lmax=1.0):
    """
    Returns a random vector of length n.
    """
    import whrandom
    new = vector([])
    gen = whrandom.whrandom()
    dl = lmax-lmin
    return vector(map(lambda x: dl*gen.random(),
		       range(n)))
	
def dot(a, b):
    """
    dot product of two vectors.
    """
    try:
	return reduce(lambda x, y: x+y, a*b, 0.)
    except:
	raise TypeError, 'vector::FAILURE in dot'

def norm(a):
    """
    Computes the norm of vector a.
    """
    try:
	return math.sqrt(abs(dot(a,a)))
    except:
	raise TypeError, 'vector::FAILURE in norm'

def sum(a):
    """
    Returns the sum of the elements of a.
    """
    try:
	return reduce(lambda x, y: x+y, a, 0)
    except:
	raise TypeError, 'vector::FAILURE in sum'

# elementwise operations
	
def log10(a):
    """
    log10 of each element of a.
    """
    try:
	return vector(map(math.log10, a))
    except:
	raise TypeError, 'vector::FAILURE in log10'

def log(a):
    """
    log of each element of a.
    """
    try:
	return vector(map(math.log, a))
    except:
	raise TypeError, 'vector::FAILURE in log'
	    
def exp(a):
    """
    Elementwise exponential.
    """
    try:
	return vector(map(math.exp, a))
    except:
	raise TypeError, 'vector::FAILURE in exp'

def sin(a):
    """
    Elementwise sine.
    """
    try:
	return vector(map(math.sin, a))
    except:
	raise TypeError, 'vector::FAILURE in sin'
	    
def tan(a):
    """
    Elementwise tangent.
    """
    try:
	return vector(map(math.tan, a))
    except:
	raise TypeError, 'vector::FAILURE in tan'
	    
def cos(a):
    """
    Elementwise cosine.
    """
    try:
	return vector(map(math.cos, a))
    except:
	raise TypeError, 'vector::FAILURE in cos'

def asin(a):
    """
    Elementwise inverse sine.
    """
    try:
	return vector(map(math.asin, a))
    except:
	raise TypeError, 'vector::FAILURE in asin'

def atan(a):
    """
    Elementwise inverse tangent.
    """	
    try:
	return vector(map(math.atan, a))
    except:
	raise TypeError, 'vector::FAILURE in atan'

def acos(a):
    """
    Elementwise inverse cosine.
    """
    try:
	return vector(map(math.acos, a))
    except:
	raise TypeError, 'vector::FAILURE in acos'

def sqrt(a):
    """
    Elementwise sqrt.
    """
    try:
	return vector(map(math.sqrt, a))
    except:
	raise TypeError, 'vector::FAILURE in sqrt'

def sinh(a):
    """
    Elementwise hyperbolic sine.
    """
    try:
	return vector(map(math.sinh, a))
    except:
	raise TypeError, 'vector::FAILURE in sinh'

def tanh(a):
    """
    Elementwise hyperbolic tangent.
    """
    try:
	return vector(map(math.tanh, a))
    except:
	raise TypeError, 'vector::FAILURE in tanh'

def cosh(a):
    """
    Elementwise hyperbolic cosine.
    """
    try:
	return vector(map(math.cosh, a))
    except:
	raise TypeError, 'vector::FAILURE in cosh'


def pow(a,b):
    """
    Takes the elements of a and raises them to the b-th power
    """
    try:
        return vector(map(lambda x: x**b, a))
    except:
        try:
		return vector(map(lambda x,y: x**y, a, b))
	except:
		raise TypeError, 'vector::FAILURE in pow'

def atan2(a,b):
    """
    Arc tangent
    """
    try:
	return vector(map(math.atan2, a, b))
    except:
	raise TypeError, 'vector::FAILURE in atan2'
	
# Vector snap to cartesian axes
# by chuck_starchaser
def vsnap(vector, vref, threshold):
  if dot(vector, vref)>=threshold:
    return vref
  else:
    return vector

def vsnapany(v, thresh=0.998):
  v = vnormal(v)
  v = vsnap(v, vector([+1,0,0]), thresh)
  v = vsnap(v, vector([-1,0,0]), thresh)
  v = vsnap(v, vector([0,+1,0]), thresh)
  v = vsnap(v, vector([0,-1,0]), thresh)
  v = vsnap(v, vector([0,0,+1]), thresh)
  v = vsnap(v, vector([0,0,-1]), thresh)
  return v

if __name__ == "__main__":
  test = vector([0.000012345, -0.00000077, 0.999999999999999876])
  test = vsnapany(test, 0.997)
  print test
