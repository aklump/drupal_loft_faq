<?php
/**
 * @file
 * Template file for category listings
 *
 * $total_faqs int Total items in all categories.
 * $total_category_faqs Total items in this category
 * $total_fags_by_category array Totals by category keys
 * $categories array All categories
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the category name
 * $question
 * $answer
 * $node
 * $theme_bottom renderable
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
?>
<div class="loft-faq-item contextual-links-region">
  <dt class="loft-faq-question"><?php print render($question) ?></dt>
  <dd class="loft-faq-answer"><?php print render($answer) ?></dd>
  <?php print render($theme_bottom); ?>
</div>
