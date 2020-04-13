#include <config_file.hpp>

using namespace tinyxml2; 

int main(){

	const char* xml_filename = "test.xml";

	
	XMLDocument doc;

doc.LoadFile(xml_filename);
if(doc.ErrorID() == 4){
printf("file %s already exist", xml_filename);
}
else{
printf("file %s doesn't exist", xml_filename);
	XMLDeclaration *header = doc.NewDeclaration();
	XMLNode *root_element = doc.NewElement("root");
	XMLElement *sol_attribute = doc.NewElement("sol");
	XMLElement *temp1 = doc.NewElement("temp1");
	XMLElement *temp2 = doc.NewElement("temp2");
	
	temp1->SetAttribute("temp1",30);
	temp2->SetAttribute("temp2",28);

	sol_attribute->SetName("sol catégorie");
	sol_attribute->SetAttribute("température", 28);
	sol_attribute->InsertEndChild(temp1);
	sol_attribute->InsertEndChild(temp2);
	doc.InsertFirstChild(root_element);
	doc.InsertFirstChild(header);

	root_element->InsertEndChild(sol_attribute);

doc.SaveFile(xml_filename,true);
}
return doc.ErrorID();
}

