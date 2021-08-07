#include <lib.h>

mapping Patterns = ([
	"checked" : ({1, "checkerboard"}),
	"chevron" : ({25, "alternating chevron"}),
	"fleur-de-lis" : ({50, "fleur-de-lis"}),
	"brocade" : ({100, "detailed floral"}),
	"chinoiserie" : ({200, "detailed scenic"}),
]);

string CraftPattern;
string SetCraftPattern(string pattern) {return CraftPattern = pattern; }
string GetCraftPattern() {return CraftPattern;}

string array GetSave() {
  return ({ "CraftPattern" });
}
