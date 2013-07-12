// Copyright (c) 1995-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

#include <IntSurf_LineOn2S.ixx>


IntSurf_LineOn2S::IntSurf_LineOn2S (const IntSurf_Allocator& theAllocator) :
    mySeq (theAllocator)
{}


Handle(IntSurf_LineOn2S) IntSurf_LineOn2S::Split (const Standard_Integer Index)
{
  IntSurf_SequenceOfPntOn2S SS;
  mySeq.Split(Index,SS);
  Handle(IntSurf_LineOn2S) NS = new IntSurf_LineOn2S ();
  Standard_Integer i;
  Standard_Integer leng = SS.Length();
  for (i=1; i<=leng; i++) {
    NS->Add(SS(i));
  }
  return NS;
}


void IntSurf_LineOn2S::InsertBefore(const Standard_Integer index, const IntSurf_PntOn2S& P) { 
  if(index>mySeq.Length()) { 
    mySeq.Append(P);
  }
  else { 
    mySeq.InsertBefore(index,P);
  }
}

void IntSurf_LineOn2S::RemovePoint(const Standard_Integer index) { 
  mySeq.Remove(index);
}
