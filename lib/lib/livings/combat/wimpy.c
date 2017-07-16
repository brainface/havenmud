/*
 * handles fleeing from combat
 * Duuktsaryth 3 February 1999
 */

private float Wimpy;
private string WimpyCmd;
private int LastWimpy;
string SetWimpyCommand(string);
string GetWimpyCommand();
float SetWimpy(float);
float GetWimpy();
int eventWimpy();
/* virtual declarations */
int GetInCombat();
void eventPrint(string);
int eventForce(string);

static void create() {
  WimpyCmd = "go out";
  Wimpy    = 0.00;
  LastWimpy = time();
}

string SetWimpyCommand(string cmd) {
  return (WimpyCmd = cmd);
}

string GetWimpyCommand() {
  return (WimpyCmd);
}

float SetWimpy(float w) { return (Wimpy = w); }

float GetWimpy()        { return (Wimpy);     }

int eventWimpy() {
  object env = environment();
  string dir, cmd;
  if (time() - LastWimpy < 20) return 0;
  if (!env) { return 0; }
  cmd = WimpyCmd || "go out";
  if ( (sscanf(cmd, "go %s", dir) && !(env->GetExit(dir)) ) || (sscanf(cmd, "enter %s", dir) && !(env->GetEnter(dir)) )) {
    string *tmp;

    tmp = filter((string *)environment()->GetExits(), (: (string)!environment()->GetDoor($1) :) );
    if (!sizeof(tmp)) { /* No exits */
      tmp = filter((string *)environment()->GetEnters(),  (: (string)!environment()->GetDoor($1) :) );
    if (!sizeof(tmp)) { /* And no enters */
        eventPrint("You attempt to flee!");
        eventPrint("There is no where to run to! Aaaaaahhhh!");
        return 0;
    }
    cmd = "enter " + tmp[random(sizeof(tmp))];
  }
  else cmd = "go " + tmp[random(sizeof(tmp))];
  }
  LastWimpy = time();
  return eventForce(cmd);
}
      
