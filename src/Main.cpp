#include "ossia-cpp98.hpp"
#include <stdlib.h>
#include <iostream>
#include <QtXml>

int main(int argc, char ** argv){

  QDomDocument doc;
  QFile file(argv[1]);
  std::cout << "Parsing  file: " << argv[1] << std::endl;
  if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file)){
      std::cout << "from.text().toStdString()" << std::endl;
      return 1;
    }
  QDomNodeList rates = doc.elementsByTagName("rate");
  for (int i = 0; i < rates.size(); i++) {
      QDomNode n = rates.item(i);
      QDomElement from = n.firstChildElement("from");
      QDomElement to = n.firstChildElement("to");
      QDomElement conversion = n.firstChildElement("conversion");

      if (from.isNull() || to.isNull() || conversion.isNull())
          continue;
      std::cout << from.text().toStdString() << std::endl;
  }
  return 0;
}
