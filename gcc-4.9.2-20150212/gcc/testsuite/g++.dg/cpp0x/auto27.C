// PR c++/51186

auto main()->int	       // { dg-error "std=" "std" { target { ! c++11 } } }
			       // { dg-error "auto" "auto" { target { ! c++11 } } 3 }
			       // { dg-error "no type" "no type" { target { ! c++11 } } 3 }
{ }
