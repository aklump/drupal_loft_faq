<?php
/**
 * @file
 * Template file for category listings
 *
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the santized category name
 * $items - an array of renderable arrays holding the items
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

  <?php foreach ($items as $item) : ?>
    <div class="loft-faq-content"><?php print render($item) ?></div><!-- /.loft-faq-content -->
  <?php endforeach; ?>

  </div><!-- /.loft-faq-category-content -->
</div><!-- /.loft-faq-category-wrapper -->
