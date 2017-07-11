string GetHelp();
mixed recursive_cp(string *source, string dest, object who);

mixed cmd(string arg) {
  object who = this_player();
  string cwd = who->query_cwd();
  string *args, *source, dest;
  int recursive;

  if (who->GetForced()) return "%^BOLD%^YELLOW%^Some asshole just tried to "
                               "force you to cp.%^RESET%^";
  if (!arg || arg == "") return GetHelp();

  args = explode(arg, " ");

  // switch to decide what to do with what
  // Yes, this method of argument checking is dirty, but works with the few
  // possible combinations that exist with this command.
  switch (sizeof(args)) {
    case 1:
      // One arg, must just be the source
      source = who->wild_card(absolute_path(cwd, args[0]));
      dest = cwd;
      break;
    case 2:
      // Two args, either recursive and source, or source and destination
      if (args[0] != "-r") {
        source = who->wild_card(absolute_path(cwd, args[0]));
        dest = absolute_path(cwd, args[1]);
      }
      else {
        recursive = 1;
        source = who->wild_card(absolute_path(cwd, args[1]));
        dest = cwd;
      }
      break;
    case 3:
      // Three args, must have specified recursive, source, and destination
      if (args[0] != "-r") return GetHelp();
      recursive = 1;
      source = who->wild_card(absolute_path(cwd, args[1]));
      dest = absolute_path(cwd, args[2]);
      break;
    default:
      // More args than this thing supports.  The user fucked up.
      return GetHelp();
  }

  if (!sizeof(source)) return "No files match.";

  if (recursive) return recursive_cp(source, dest, who);

  if (sizeof(source) > 1) {
    int count;
    if (file_size(dest) != -2) return GetHelp();
    who->eventPrint("Starting to cp...");
    foreach (string f in source) {
      int i = file_size(f);
      if (i == -1) {
        who->eventPrint("  Can't read " + f);
        continue;
      }
      if (i == -2) {
        who->eventPrint("  " + f + " is a directory.  Skipping.");
        continue;
      }
      if (f == dest+"/"+get_dir(f)[0]) {
        who->eventPrint("  Can't copy " + f + " on to itself.");
        continue;
      }
      i = cp(f, dest+"/"+get_dir(f)[0]);
      if (!(i == 1)) {
        who->eventPrint("  Error copying "+f+" to "+dest+"/"+get_dir(f)[0]);
        continue;
      }
      who->eventPrint("  Copied "+f+" to "+dest+"/"+get_dir(f)[0]);
      count++;
    }
    return sprintf("%d files copied.\n", count);
  }
  if (file_size(source[0]) < 0) return GetHelp();
  if (file_size(dest) == -2) dest = dest+"/"+get_dir(source[0])[0];
  if (source[0] == dest) return "Can't copy " + source[0] + " on to itself.";
  if (cp(source[0], dest) != 1) return "Error copying "+source[0]+" to "+dest;
  return "Copied "+source[0]+" to "+dest;
}

mixed recursive_cp(string *source, string dest, object who) {
  return "Recursive does not work yet.";
}

string GetHelp() {
  return "The help for this command should be displayed here.";
}
