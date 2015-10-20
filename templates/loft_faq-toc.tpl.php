<?php
/**
 * @file
 * Renders content for the table of contents
 *
 * $total_faqs int Total items in all categories.
 * $total_fags_by_category array Totals by category keys
 * $items - an array of key/values where key is the anchor id and value is the
 * - key: the value to use in the href attribute of the anchor tag = the name of
 * the <a> above the actual items
 * - value: The safe value for printing, be careful if running this though t()
 *  as you'll get double sanitization.
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
?>
<a name="loft-faq-toc"></a>
<ol class="loft-faq-toc">
<?php foreach ($items as $anchor => $group) : ?>
  <li><a href="#<?php print $anchor ?>"><?php print t('!group FAQs', array(
    '!group' => $group,
  )) ?></a></li>
<?php endforeach; ?>
</ol>
