<?php
/**
 * @file
 * Renders content for the table of contents
 *
 * $items - an array of key/values where key is the anchor id and value is the
   group
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
?>
<a name="loft-faq-toc"></a>
<ol class="loft-faq-toc">
<?php foreach ($items as $anchor => $group) : ?>
  <li><a href="#<?php print $anchor ?>"><?php print t('@group FAQs', array(
    '@group' => $group,
  )) ?></a></li>
<?php endforeach; ?>
</ol>
