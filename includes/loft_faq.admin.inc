<?php
/**
 * @file
 * admin functions
 *
 */

/**
 * This is NOT a hook, but a helper to modify the FAQ node type form.
 *
 * @param  array &$form
 *
 * @see  loft_faq_form_alter()
 */
function _loft_faq_faq_form_alter(&$form) {
  global $_loft_faq_type_;
  $info          = loft_faq_get_pages_info('config');
  $display_nid   = isset($_GET['loft_faq_display']) ? $_GET['loft_faq_display'] : NULL;
  $info          = isset($info[$display_nid]) ? $info[$display_nid] : array();

  $default_group = variable_get('loft_faq_group_default', LOFT_FAQ_GROUP_DEFAULT);
  $default_group = isset($info['default_category']) ? $info['default_category'] : $default_group;

  $group_field = variable_get('loft_faq_group_fieldname', LOFT_FAQ_GROUP_FIELDNAME);
  if ($group_field) {

    // 
    // 
    // Connect $type based on field structure.
    // 
    if (isset($form[$group_field]['und'][0]['value']['#type'])) {
      // textfield
      $type = &$form[$group_field]['und'][0]['value']['#type'];
    } else {
      // select
      $type  = &$form[$group_field]['und']['#type'];
    }

    // 
    // 
    // Connect $description based on field structure.
    // 
    $description_suffix = ' ' . t('If unsure enter %default.', array('%default' => $default_group));
    $description = &$form[$group_field]['und']['#description'];
    $description = trim($description . $description_suffix);
    if (isset($form[$group_field]['und']['0']['value']['#description'])) {
      $description = &$form[$group_field]['und']['0']['value']['#description'];
      $description = trim($description . $description_suffix);
    }
    
    // 
    // 
    // Make textfields use autocomplete.
    // 
    if ($type === 'textfield') {
      $form[$group_field]['und'][0]['value']['#autocomplete_path'] = LOFT_FAQ_AUTOCOMPLETE . '/' . $_loft_faq_type_ . '/group';
    }
  
    // 
    // 
    // Connect $default based on field structure.
    // 
    if (isset($form[$group_field]['und']['#default_value'])) {
      // select
      $default = &$form[$group_field]['und']['#default_value'];
    }
    else {
      // textfield
      $default = &$form[$group_field]['und'][0]['value']['#default_value'];
    }
    if (empty($default) && variable_get('loft_faq_set_default', 
      LOFT_FAQ_SET_DEFAULT)) {
      $default = $default_group;
    }

    // 
    // 
    // Hide the field if configured to do so.
    // 
    if (array_key_exists('hide_category_input', $info)) {
      $form[$group_field]['#access'] = $info['hide_category_input'];
    }
  }
}

/**
 * Return the list of autocomplete suggestions
 *
 * @param string $node_type
 * @param string $field
 * @param string $string
 *   The user input
 *
 * @return json
 */
function loft_faq_autocomplete($node_type, $field, $string = '') {
  global $_loft_faq_type_;
  $matches     = array();
  $suggestions = array();
  if ($string) {
    switch ($node_type) {
      case $_loft_faq_type_:
        switch ($field) {

          //find all the matching fieldgroups
          case 'group':
            foreach (loft_faq_get_faq_categories() as $category) {
              //the string is anywhere in the choice
              if (stristr($category, $string) !== FALSE) {
                $suggestions[$category] = $category;
              }
            }
            break;
        }
        break;
    }
  }
  drupal_json_output($suggestions);
  drupal_exit();
}

