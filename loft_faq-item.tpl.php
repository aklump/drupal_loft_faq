<?php
/**
 * @file
 * Template file for category listings
 *
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the category name
 * $question
 * $answer
 * $node
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
?>
<dt class="loft-faq-question"><?php print render($question) ?></dt>
<dd class="loft-faq-answer"><?php print render($answer) ?></dd>
