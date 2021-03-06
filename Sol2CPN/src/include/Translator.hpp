#ifndef SOL2CPN_TRANSLATOR_H_
#define SOL2CPN_TRANSLATOR_H_

/*#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

*/
#include "Helena.hpp"
#include "nlohmann/json.hpp"
#include "ASTNodes.hpp"

namespace SOL2CPN {

class Translator {
public:
    Translator(RootNodePtr _rootNode) : rootNode(_rootNode) {}
    NetNodePtr translate();

private:
RootNodePtr rootNode;
NetNodePtr net;
std::map< ASTNodePtr, ColorNodePtr> type_correspondance;
std::map< VariableDeclarationNodePtr, ColorNodePtr> variable_type_list;

void generatePredefinedColors();
void generateUserBehaviourColors();
StructColorNodePtr translateStruct(StructDefinitionNodePtr struct_node);
ListColorNodePtr translateMapping(ASTNodePtr _node);
StructColorNodePtr generateFunctionParametersColor(FunctionDefinitionNodePtr function_node);
StructColorNodePtr generateStateColor();
ColorNodePtr elementaryToColor(VariableDeclarationNodePtr _var);
};

}

#endif //SOL2CPN_TRANSLATOR_H_