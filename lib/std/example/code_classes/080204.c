/*  This file is for the class
 * "Functions and Arguments:  Understanding how the lib works"
 *  Duuk@Haven 08/02/04
 */

int Integer;

int SetInteger(int x) { 
  return Integer = x;
}

int ShowLevel(object who) {
	int x;
	
	x = who->GetLevel();
	return x;
}

int GetInteger() {
	return Integer;
}

void ReturnNothing() {
}

string GetName(object who) {
	return who->GetKeyName();
}

string BigLevel(object who) {
	int x;
	x = who->GetLevel();
	
	if (x > 10) return "Woo Bigger than 10!";
	return "No, Loser!";
}
