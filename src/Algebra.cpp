
#include <soth/Algebra.h>

using namespace soth;

MATLAB::MATLAB( const VectorXd& v1 )
      {
	std::ostringstream os; os << "[ ";
	for( unsigned int i=0;i<v1.size();++i )
	  {
	    {os << " "; double a=v1(i);  os << a;}
	    //DEBUGos <<  v1(i);
	    if( v1.size()!=i+1 ) { os << ", "; }
	  }
	os << "]';";
	str = os.str();
      }
MATLAB::MATLAB( const VectorXi& v1 )
      {
	std::ostringstream os; os << "[ ";
	for( unsigned int i=0;i<v1.size();++i )
	  {
	    {os << " "; double a=v1(i);  os << a;}
	    //DEBUGos <<  v1(i);
	    if( v1.size()!=i+1 ) { os << ", "; }
	  }
	os << "]';";
	str = os.str();
      }


template< typename bubTemplateMatrix >
void initMATLABFromBubMatrix( MATLAB& matlab, const bubTemplateMatrix& m1)
      {
	//MATLAB::fullPrec=false;
	std::ostringstream os; os << "[ ";
	std::ostringstream ostmp;
	for( unsigned int i=0;i<m1.rows();++i )
	  {
	    for( unsigned int j=0;j<m1.cols();++j )
	      {
		if( m1(i,j)<0 ) ostmp << "-"; else ostmp << " ";
		if(MATLAB::fullPrec||fabs(m1(i,j))>1e-6) ostmp <<  fabs(m1(i,j));
		else { ostmp << "0"; }
		if( m1.cols()!=j+1 )
		  {
		    ostmp << ",";
		    const int size = ostmp.str().length();
		    for( unsigned int i=size;i<8;++i) ostmp<<" ";
		    ostmp << "\t";
		  }
		os << ostmp.str(); ostmp.str("") ;
	      }
	    if( m1.rows()!=i+1 ) { os << " ;" << std::endl<<"  "; }
	    else { os << "  ];"; }
	  }
	matlab.str = os.str();
      }


MATLAB::MATLAB( const MatrixXd& m1)
{initMATLABFromBubMatrix(*this,m1);}

namespace soth
{
  std::ostream & operator << (std::ostream & os, const MATLAB & m )
  {return os << m.str; }
}
