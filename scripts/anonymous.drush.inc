<?php

/**
 * @file
 *   Anonymous drush command.
 *
 *   To run this command, execute `drush -r ../htdocs --include=../scripts anonymous`
 *   from within your drush directory.
 *
 */

define('ANONYMOUS_IP', '127.0.0.1');
define('ANONYMOUS_NAME', 'Anony, Mous');
define('ANONYMOUS_ORGANIZATION', 'Anonymous Organization');
define('ANONYMOUS_PROJECT', 'Anonymous Project');
define('ANONYMOUS_DELETED', '--DELETED--');
define('ANONYMOUS_PROVIDER', 'Anonymous Provider');
define('ANONYMOUS_TASK', 'Anonymous Task');
define('ANONYMOUS_TEAM', 'Anonymous Team-Person');
define('ANONYMOUS_TICKET', 'Anonymous Ticket');
define('ANONYMOUS_TERM', 'Anonymous Term');
define('ANONYMOUS_USERNAME', 'anonymous');


/**
 * Implementation of hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 */
function anonymous_drush_command() {
  $items = array();

  // The 'anonymous' command
  $items['anonymous'] = array(
    'description' => "Make all Data in the DB anonymous. BE CARFULE WITH THIS COMMAND!",
    'arguments' => array(),
    'options' => array(),
    'examples' => array(
      'drush anonymous' => 'Make all data anonymous',
    ),
//    'aliases' => array('mmas'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE, // No bootstrap at all.
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'. This hook is optional. If a command
 * does not implement this hook, the command's description is used instead.
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function sandwich_drush_help($section) {
  switch ($section) {
    case 'drush:anonymous':
      return dt("This command will make all data in the Database anonymous. IPS to 127.0.0.1, names to anonymous. BE CARFULE WITH THIS COMMAND!");
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate().
 *
 * The validate command should exit with
 * `return drush_set_error(...)` to stop execution of
 * the command.  In practice, calling drush_set_error
 * OR returning FALSE is sufficient.  See drush.api.php
 * for more details.
 */
function drush_anonymous_validate() {
  return TRUE;
}

/**
 * drush_COMMAND()
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_anonymous() {
  
  $anonymous_info = array();
  
  if (db_table_exists('webform_submitted_data')) {
    $anonymous_info += array(
      'webform_submitted_data' => array('data' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('simplenews_subscriptions')) {
    $anonymous_info += array(
      'simplenews_subscriptions' => array('mail' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('comments')) {
    $anonymous_info += array(
      'comments' => array(
          'hostname' => ANONYMOUS_IP, 
          'name' => array("'".ANONYMOUS_USERNAME."-'", 'uid'), 
          'subject' => array("'SUBJECT-'", 'cid'), 
          'comment' => ANONYMOUS_DELETED,
      ),
    );
  }
  
  if (db_table_exists('stormexpense')) {
    $anonymous_info += array(
      'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
      'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
      'provider_title' => array("'".ANONYMOUS_PROVIDER."-'", 'provider_nid'),
    );
  }
  
  if (db_table_exists('cost_unit')) {
    $anonymous_info += array(
      'cost_unit' => array('organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid')),
    );
  }
  
  if (db_table_exists('cost_unit_projects')) {
    $anonymous_info += array(
      'cost_unit_projects' => array('project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid')),
    );
  }
  
  if (db_table_exists('pm_message')) {
    $anonymous_info += array(
      'pm_message' => array(
          'subject' => array("'SUBJECT-'", 'mid'), 
          'body' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('profile_values')) {
    $anonymous_info += array(
      'profile_values' => array('value' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('purchase_requisition')) {
    $anonymous_info += array(
      'purchase_requisition' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'),
      ),
    );
  }
  
  if (db_table_exists('purchase_requisition_ressource_columns')) {
    $anonymous_info += array(
      'purchase_requisition_ressource_columns' => array('description' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('stormexpense')) {
    $anonymous_info += array(
      'stormexpense' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'provider_title' => array("'".ANONYMOUS_PROVIDER."-'", 'provider_nid')
      ),
    );
  }
  
  if (db_table_exists('storminvoice')) {
    $anonymous_info += array(
      'storminvoice' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid')
      ),
    );
  }
  
  if (db_table_exists('storminvoice_items')) {
    $anonymous_info += array(
      'storminvoice_items' => array('description' => ANONYMOUS_DELETED),
    );
  }
  
  if (db_table_exists('stormnote')) {
    $anonymous_info += array(
      'stormnote' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'task_title' => array("'".ANONYMOUS_TASK."-'", 'task_nid')
      ),
    );
  }
  
  if (db_table_exists('stormorganization')) {
    $anonymous_info += array(
      'stormorganization' => array(
          'fullname' => array("'".ANONYMOUS_ORGANIZATION."-'", 'nid'), 
          'provstate' => ANONYMOUS_DELETED, 
          'city' => ANONYMOUS_DELETED, 
          'zip' => '00000', 
          'address' => ANONYMOUS_DELETED, 
          'taxid' => "DE111111111", 
          'email' => ANONYMOUS_DELETED, 
          'www' => ANONYMOUS_DELETED, 
          'phone' => ANONYMOUS_DELETED
       ),
    );
  }
  
  if (db_table_exists('stormperson')) {
    $anonymous_info += array(
      'stormperson' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'prefix' => "", 
          'fullname' => array("'".ANONYMOUS_NAME."-'", 'nid'), 
          'email' => ANONYMOUS_DELETED, 
          'www' => "", 
          'phone' => "", 
          'im' => ""
       ),
    );
  }
  
  if (db_table_exists('stormproject')) {
    $anonymous_info += array(
      'stormproject' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'manager_title' => array("'".ANONYMOUS_NAME."-'", 'manager_nid'), 
          'assigned_title' => array("'".ANONYMOUS_TEAM."-'", 'assigned_nid'),
      ),
    );
  }
  
  if (db_table_exists('stormtask')) {
    $anonymous_info += array(
      'stormtask' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'assigned_title' => array("'".ANONYMOUS_TEAM."-'", 'assigned_nid'),
      ),
    );
  }
  
  if (db_table_exists('stormticket')) {
    $anonymous_info += array(
      'stormticket' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'task_title' => array("'".ANONYMOUS_TASK."-'", 'task_nid'), 
          'assigned_title' => array("'".ANONYMOUS_TEAM."-'", 'assigned_nid'),
      ),
    );
  }
  
  if (db_table_exists('stormtimetracking')) {
    $anonymous_info += array(
      'stormtimetracking' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'task_title' => array("'".ANONYMOUS_TASK."-'", 'task_nid'), 
          'ticket_title' => array("'".ANONYMOUS_TICKET."-'", 'ticket_nid'),
      ),
    );
  }
  
  if (db_table_exists('stormtimetracking_favorites')) {
    $anonymous_info += array(
      'stormtimetracking_favorites' => array(
          'organization_title' => array("'".ANONYMOUS_ORGANIZATION."-'", 'organization_nid'), 
          'project_title' => array("'".ANONYMOUS_PROJECT."-'", 'project_nid'), 
          'task_title' => array("'".ANONYMOUS_TASK."-'", 'task_nid'),
      ),
    );
  }
  /*
  if (db_table_exists('term_data')) {
    $anonymous_info += array(
      'term_data' => array(
          'name' => array("'".ANONYMOUS_TERM."-'", 'tid'), 
          'description' => "",
      ),
    );
  }
  */
  if (db_table_exists('users')) {
    $anonymous_info += array(
      'users' => array(
          'mail' => array("'del@eted.'", 'uid'), 
          'init' => array("'del@eted.'", 'uid'), 
          'name' => array("'".ANONYMOUS_USERNAME."-'", 'uid'),
      ),
    );
  }
  
  if (db_table_exists('forward_log')) {
    $anonymous_info += array(
      'forward_log' => array(
          'hostname' => ANONYMOUS_IP, 
      ),
    );
  }
  
  foreach ($anonymous_info as $table => $fields) {
    $sql = "UPDATE {$table} SET ";
    $sql_set = array();
    $args = array();
    foreach ($fields as $field_name => $field_value) {
      if (is_array($field_value)) {
        $sql_concat = $sql.$field_name." = CONCAT(".implode(', ', $field_value).") WHERE ";
        $nid_name = array_pop($field_value);
        if ($table=='users') {
          // do not touch admin user!
          $sql_concat .= $nid_name." > 1";
        }
        else {
          $sql_concat .= $nid_name." <> 0";
        }
        db_query($sql_concat);
      }
      else {
        $sql_set[] = "$field_name = '%s'";
        $args[] = $field_value;
      }
    }
    if (!empty($sql_set)) {
      $sql = $sql . implode(', ', $sql_set);
      db_query($sql, $args);
    }
    drush_print("Table ".$table." is now anonymous\n");
  }

  // set node titles
  $result = db_query("SELECT name, type FROM {node_type}");
  while($row = db_fetch_array($result)) {
    $name = $row['type'];
    $title = $row['name'];
    $sql_set = "";
    $args = array();
    
    if (in_array($name, array(
        'stormorganization', 
        'stormperson', 
        'stormproject',
        'stormticket',
        'stormtask',
        'stormteam',
        ))) {
    
      switch($name) {
        case 'stormorganization':
          $sql_set = "title = CONCAT('".ANONYMOUS_ORGANIZATION."-', n.nid)";
          break;
        case 'stormperson':
          $sql_set = "title = CONCAT('".ANONYMOUS_NAME."-', n.nid)";
          break;
        case 'stormproject':
          $sql_set = "title = CONCAT('".ANONYMOUS_PROJECT."-', n.nid)";
          break;
        case 'stormticket':
          $sql_set = "title = CONCAT('".ANONYMOUS_TICKET."-', n.nid)";
          break;
        case 'stormtask':
          $sql_set = "title = CONCAT('".ANONYMOUS_TASK."-', n.nid)";
          break;
        case 'stormteam':
          $sql_set = "title = CONCAT('".ANONYMOUS_TEAM."-', n.nid)";
          break;
      }
      $sql = "UPDATE {node} n SET ".$sql_set." WHERE type = '%s'";
      $args[] = $name;
      db_query($sql, $args);
      drush_print("Table node (type: $title) is now anonymous\n");

      $sql = "UPDATE {node_revisions} nr, {node} n SET nr.".$sql_set.", nr.body='%s', nr.teaser='%s' WHERE n.type = '%s' AND n.nid = nr.nid AND n.vid = nr.vid";
      $args[] = ANONYMOUS_DELETED;
      $args[] = ANONYMOUS_DELETED;
      $args[] = $name;
      db_query($sql, $args);

      drush_print("Table node_revision (type: $title) is now anonymous\n");
    }
  }
  
  if (db_table_exists('stormteam')) {
    // change team user names
    $result = db_query("SELECT vid, nid, members FROM {stormteam}");
    while($row = db_fetch_array($result)) {
      $members = unserialize($row['members']);
      foreach ($members as $nid => &$name) {
        $name = ANONYMOUS_NAME.'-'.$nid;
      }
      $members = serialize($members);
      db_query("UPDATE {stormteam} SET members = '%s' WHERE nid = %d AND vid = %d", $members, $row['nid'], $row['vid']);
    }
    drush_print("Table storm_team is now anonymous\n");
  }

  drush_print("\nAll personal information data cleared\n");
}
