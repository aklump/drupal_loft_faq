<?php
// $Id$

/**
 * @file
 * Template file for category listings
 *
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the category name
 * $nodes - an array of nodes within the category
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{ 
 */
?>
<a name="<?php print $anchor ?>"></a>
<div class="loft-faq-category-wrapper <?php print $anchor ?>">
  <h2 class="view-title loft-faq-category"><?php print $category ?></h2>
  <a class="loft-faq-top" href="#loft-faq-toc"><?php print t('Back to Index') ?></a>
  <div class="loft-faq-category-content">
  
  <?php foreach ($nodes as $node) : ?>
    <div class="loft-faq-content"><?php print node_view($node, FALSE, FALSE, FALSE) ?></div><!-- /.loft-faq-content -->
  <?php endforeach; ?>
  
  </div><!-- /.loft-faq-category-content -->
</div><!-- /.loft-faq-category-wrapper -->
