/* Written for Silenus by Duuk@Haven */

string this_directory(mixed args) {
  string *tmp;
  if (objectp(args)) args = base_name(args);
  tmp = explode(args, "/");
  args = implode(tmp[0..sizeof(tmp)-2], "/");
  return "/" + args;
}