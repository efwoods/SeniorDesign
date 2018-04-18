function bio=E_stopnewbio
bio = [];
bio(1).blkName='Constant1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&E_stopnew_B.Constant1';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='Relational Operator';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&E_stopnew_B.RelationalOperator';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='Q4 AD';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&E_stopnew_B.Q4AD';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

function len = getlenBIO
len = 3;

