

void debugger(string who, string what) {
  object ob = find_living(who);
  if (!ob) return;
  ob->eventPrint(what);
  return;
}
