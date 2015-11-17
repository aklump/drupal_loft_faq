<?php
/**
 * @file
 * Provides theming
 *
 */

/**
 * Implements hook_preprocess_loft_faq_item().
 */
function loft_faq_preprocess_loft_faq_item(&$vars) {
  $node = $vars['elements']['#node'];

  //menu_contextual_links()
  $vars['links'] = array(
    '#type' => 'contextual_links',
    // Each key is the name of the implementing module, and each value is an
    // array that forms the function arguments for menu_contextual_links()
    '#contextual_links' => array(
      'loft_faq' => array('node/' . $node->nid, array()),
    ),
  );

  $vars['question'] = array('#markup' => check_plain($node->title));
  $vars['answer'] = field_view_value('node', $node, 'body', $node->body['und'][0]);
}

/**
 * Make a css safe class or id
 *
 * @param string or array $input
 *   The string will be made css safe; array values will be made css safe
 * @param bool $flatten
 *   Optional.  Set to TRUE to flatten arrays into space separated strings
 *
 * @return string or array
 */
function loft_faq_css_safe($input, $flatten = FALSE) {
  if (is_array($input)) {
    $function = __FUNCTION__;
    foreach ($input as $key => $value) {
      $input[$key] = $function($value);
    }
    return $flatten ? trim(implode(' ', $input)) : $input;
  }
  elseif (is_string($input)) {
    return trim(drupal_strtolower(preg_replace('/[\W_]+/', '-', $input)), '-');
  }
  return $input;
}
