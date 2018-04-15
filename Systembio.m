function bio=Systembio
bio = [];
bio(1).blkName='Magnet_Control';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&System_B.Magnet_Control';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='Q4 AD';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&System_B.Q4AD';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

function len = getlenBIO
len = 2;

