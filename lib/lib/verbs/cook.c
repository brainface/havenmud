/* cook verb handling */
int eventDestruct();

mixed direct_cook_obj() {
  return 1;
}

int eventCook(object who, int skill_level) {
  send_messages("cook", "$agent_name $agent_verb $target_name.", who, this_object(), environment(who));
  eventDestruct();
  return 1;
}