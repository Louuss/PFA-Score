cp AbletonFiles/$1\ Project/$1.als abletonXml/$1.gz
gzip -d abletonXml/$1.gz
mv abletonXml/$1 abletonXml/$1.xml
