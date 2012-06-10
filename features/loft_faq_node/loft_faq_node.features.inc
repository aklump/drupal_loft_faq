<?php
/**
 * @file
 * loft_faq_node.features.inc
 */

/**
 * Implements hook_views_api().
 */
function loft_faq_node_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function loft_faq_node_node_info() {
  $items = array(
    'loft_faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Add a question/answer to the FAQ section'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  return $items;
}
