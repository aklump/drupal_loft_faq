<?php
/**
 * @file
 * API documentation for loft_faq module.
 *
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_loft_faq_get_node_category_alter().
 *
 * Use when using an alternative storage method for the category.
 *
 * It may be much easier to just set the var: loft_faq_group_fieldname instead.
 *
 * @param string &$category
 * @param object $node
 *
 * @return NULL
 */
function hook_loft_faq_get_node_category_alter(&$category, $node) {

}

/**
 * Implements hook_loft_faq_set_node_category_alter().
 *
 * Use when using an alternative storage method for the category.
 *
 * It may be much easier to just set the var: loft_faq_group_fieldname instead.
 * 
 * @param object $node
 * @param string $category
 *
 * @return NULL
 */
function hook_loft_faq_set_node_category_alter($node, $category) {

}

/**
 * Implements hook_loft_faq_item_alter().
 *
 * Adds the SANITIZED values for #question and #answer
 *
 * @param array &$item
 *
 * $item
 * - #category
 * - #anchor
 * - #node
 *
 * @see loft_faq_node_view()
 */
function hook_loft_faq_item_alter(&$item) {
  $item['#question'] = array('#markup' => check_plain($item['#node']->title));
  $item['#answer'] = array('#markup' => $item['#node']->body['und'][0]['safe_value']);
}

/**
 * Implements hook_loft_faq_node_append().
 *
 * @return array
 * - each item is an array of parameters
 *
 * @see loft_faq_node_view()
 */
function hook_loft_faq_node_append() {
  return array(
    array(
      'nid' => variable_get('loft_faq_faq_page_nid', NULL),
    ),
    array(
      'nid' => 384023,

      // The Table of Contents
      'toc' => FALSE,
      'title' => t('Mobile App FAQs'),
      'title_display' => 'invisible',
      
      // The categories
      'categories' => array(
        'Consumers'
      ),
      'not_categories' => array(),

      // The node edit form, when $_GET['loft_faq_display'] is set for context.
      // This should be one of categories above.
      'default_category' => 'Consumers',
      'hide_category_input' => FALSE,      
    )
  );
}

/**
 * Implements hook_loft_faq_categories_alter().
 *
 * Allows modules to alter the category list, such as order.
 */
function hook_loft_faq_categories_alter(&$categories) {
  // do something like reorder the categories...
  $categories = array_unique(array_merge(array('Products', 'Orders'), $categories));
}