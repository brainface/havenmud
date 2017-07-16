#include <lib.h>
#include <dirs.h>

inherit LIB_DAEMON;
private mapping Failures;
void LoadFailures();

static void create() {
  ::create();
  SetNoClean(1);
  Failures = ([
    "minor"        : ({ }),
    "moderate"     : ({ }),
    "major"        : ({ }),
    "catastrophic" : ({ }),
    ]);
  LoadFailures();
}
    
string GetFailure(string level) {
	string *failures;
	
  LoadFailures();
	failures = Failures[level];
	
	if (!sizeof(failures)) {
		return 0;
	}
	return (DIR_STD + "failure/" + level + "/" + failures[random(sizeof(failures))]);
}

void LoadFailures() {
  Failures["minor"] = unguarded( (: get_dir, DIR_STD "failure/minor/*.c" :) );
  Failures["moderate"] = unguarded( (: get_dir, DIR_STD "failure/moderate/*.c" :) );
  Failures["major"] = unguarded( (: get_dir, DIR_STD "failure/major/*.c" :) );
  Failures["catastrophic"] = unguarded( (: get_dir, DIR_STD "failure/catastrophic/*.c" :));
  return;
}

varargs mixed GetFailureList(string level) {
	LoadFailures();
	if (!level) return Failures;
	return Failures[level];
}
