<?php
/**
 * @file
 * Provides theming
 *
 */

/**
 * Adds in defaults if the keys are empty in $vars.
 *
 * @code
 *   _loft_faq_defaults_if_empty($vars, array(
 *     'subject' => t('Story of the Month'),
 *     'target_href' => '#',
 *   ));
 * @endcode
 *
 * @param  array &$vars
 * @param  array $defaults Keys and default values.
 */
function _loft_faq_defaults_if_empty(&$vars, $defaults) {
  foreach ($defaults as $key => $default) {
    if (empty($vars[$key])) {
      $vars[$key] = $default;
    }
  }
}

/**
 * Implements hook_preprocess_loft_faq_list().
 */
function loft_faq_preprocess_loft_faq_list(&$vars) {
  global $_loft_faq_type_;
  $vars['wrapper_attributes']['class'][] = 'contextual-links-region';
  $vars['theme_bottom']['links'] = array(
    '#type' => 'contextual_links',
    '#contextual_links' => array(
      'views' => array('admin/structure/views/view', array($_loft_faq_type_)),
    ),
  );
  $vars = _loft_faq_get_category_totals($vars['items'], $vars['category']) + $vars;
}

/**
 * Helper function to analyze all items and compute category vars.
 *
 * @param  array $items An array of faq items.
 * @param  string $category The category of the context.
 *
 * @return array
 *   - keys are var names for the themes.
 */
function _loft_faq_get_category_totals(&$items, $category = '') {
  $vars             = array('total_faqs' => count($items), 'category' => $category);
  $categories       = array();
  
  foreach ($items as $item) {
    if (empty($item['category']) && !empty($item['#node'])) {
      $item['category'] = loft_faq_get_node_category($item['#node']);
    }
    $categories[$item['category']] = isset($categories[$item['category']]) ? ++$categories[$item['category']] : 1;
  }
  
  $vars['total_category_faqs']    = $category ? count($categories[$category]) : $vars['total_faqs'];
  $vars['total_faqs_by_category'] = $categories;
  $vars['categories']             = array_keys($categories);

  return $vars;
}

/**
 * Implements hook_preprocess_loft_faq_item().
 */
function loft_faq_preprocess_loft_faq_item(&$vars) {
  global $_loft_faq_type_;

  // If we have a node we can pull values from it.
  if (isset($vars['node']) && $vars['node']->type === $_loft_faq_type_) {
    $node = $vars['node'];

    _loft_faq_defaults_if_empty($vars, array(
      'category' => loft_faq_get_node_category($node),
      'question' => array('#markup' => check_plain($node->title)),
      'answer'   => field_view_value('node', $node, 'body', $node->body['und'][0]),
    ));
    
    $vars['links'] = array(
      '#type' => 'contextual_links',
      '#contextual_links' => array(
        'loft_faq' => array('node/' . $node->nid, array()),
      ),
    );
  }

  $vars['total_faqs']          = array_sum($vars['total_faqs_by_category']);
  $vars['categories']          = array_keys($vars['total_faqs_by_category']);
  $vars['total_category_faqs'] = isset($vars['total_faqs_by_category'][$vars['category']]) ? $vars['total_faqs_by_category'][$vars['category']] : 0;
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
