<?php
/**
 * @file
 * Administration page callbacks for the loft_faq module.
 *
 * @ingroup loft_faq
 * @{
 */

/**
 * Form builder. Configure my_module.
 *
 * @ingroup forms
 * @see system_settings_form()
 */

function loft_faq_admin_settings() {
  $form = array();

  $form['#old_nid'] = variable_get('loft_faq_faq_page_nid', NULL);

  $form['loft_faq_faq_page_nid'] = array(
    '#type' => 'textfield',
    '#description' => t("Create a page node and enter it's node id here.  The FAQs will be appended to the content of this node."),
    '#title' => t('FAQ page NID'),
    '#default_value' => variable_get('loft_faq_faq_page_nid', NULL),
    '#required' => TRUE,
    '#size' => 20,
  );

  $options = array();
  foreach (node_type_get_types() as $type) {
    $options[$type->type] = $type->name;
  }
  $form['loft_faq_node_type'] = array(
    '#type' => 'select',
    '#title' => t('FAQ node type'),
    '#default_value' => variable_get('loft_faq_node_type', LOFT_FAQ_NODE_TYPE),
    '#options' => $options,
    '#description' => t('This node type will be considered the FAQ node type.'),
  );

  $original = variable_get('loft_faq_group_default', LOFT_FAQ_GROUP_DEFAULT);
  $form['loft_faq_group_default'] = array(
    '#type' => 'textfield',
    '#title' => t('Default group for questions'),
    '#description' => t('Changing this field value <em>after content has been assigned "%default"</em>, will result in said content automatically being updated to the new value.', array('%default' => $original)),
    '#default_value' => $original,
  );

  $form['loft_faq_set_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prefill group for new FAQs?'),
    '#default_value' => variable_get('loft_faq_set_default', LOFT_FAQ_SET_DEFAULT),
    '#description' => t('Check this box and the default group will be already entered in the group box on the FAQ node form.'),
  );

  $form['#submit'][] = 'loft_faq_admin_settings_submit';

  return system_settings_form($form);
}

/**
 * Form submission handler for loft_faq_admin_settings().
 *
 * @see loft_faq_admin_settings()
 */
function loft_faq_admin_settings_submit($form, &$form_state) {

  // If the default type gets changed we are going to update the database directly.
  $original = variable_get('loft_faq_group_default', LOFT_FAQ_GROUP_DEFAULT);
  if (($new = $form_state['values']['loft_faq_group_default']) !== $original) {

    // Load and alter all nodes with the original category to the new one.
    $need_update = loft_faq_get_faq_by_category($original, TRUE);
    $updated = 0;
    foreach ($need_update as $node) {
      loft_faq_set_node_category($node, $new);
      node_save($node);
      ++$updated;
    }
    if ($updated) {
      drupal_set_message(t("We updated the category for @count from %old to %new.", array(
        '@count' => format_plural($updated, '1 faq', '@count faqs'),
        '%old' => $original, 
        '%new' => $new, 
      )), 'status', FALSE);
    }
  }

  if (($nid = $form_state['values']['loft_faq_faq_page_nid']) != $form['#old_nid'] &&
      ($node = node_load($nid))) {

    $query = db_select('menu_links', 'm');
    $item_exists = $query
      ->fields('m', array('mlid'))
      ->condition('link_path', 'node/' . $nid)
      ->range(0, 1)
      ->countQuery()
      ->execute()
      ->fetchField();

    // We have a new node, let's create the menu item for it, but only once per nid
    if (!$item_exists && !variable_get('loft_faq_auto_menu_item_' . $nid)) {
      variable_set('loft_faq_auto_menu_item_' . $nid, TRUE);
      $item = array(
        'link_title' => t('FAQ'),
        'link_path' => 'node/' . $nid,
        'router_path' => 'node/%',
        'menu_name' => 'main-menu',
        'options' => array(
          'attributes' => array(
            'title' => t('Review our Frequently Asked Questions'),
          ),
        ),
      );

      $item['mlid'] = menu_link_save($item);
      menu_cache_clear_all();
      drupal_set_message(t('An FAQ link has been added to the menu.'));
    }
  }
}

/** @} */ //end of group loft_faq
