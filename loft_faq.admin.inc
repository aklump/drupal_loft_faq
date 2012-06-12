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
 * @see system_settings_form().
 */

function loft_faq_admin_settings() {
  $form = array();

  $form['loft_faq_faq_page_nid'] = array(
    '#type' => 'textfield',
    '#description' => t("Create a page and then enter it's node id here.  The FAQs will be appended to that page."),
    '#title' => t('FAQ Page NID'),
    '#default_value' => variable_get('loft_faq_faq_page_nid', NULL),
    '#required' => TRUE,
    '#size' => 20,
  );

  $form['loft_faq_group_default'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Group for Questions'),
    '#default_value' => variable_get('loft_faq_group_default', LOFT_FAQ_GROUP_DEFAULT),
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

  if (($nid = $form_state['values']['loft_faq_faq_page_nid']) != $form['#old_nid'] &&
       ($node = node_load($nid))) {

    $item_exists = db_result(db_query("SELECT COUNT(*) FROM {menu_links} WHERE link_path = 'node/%d' LIMIT 1", $nid));

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
      drupal_set_message(t('An FAQ link has been added to the menu.'));
    }
  }
}

/** @} */ //end of group loft_faq
