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
  <dl class="loft-faq-category">
    <?php foreach ($items as $item) : ?>
      <?php print render($item) ?>
    <?php endforeach; ?>
  </dl><!-- /.loft-faq-content -->
  <a class="loft-faq-top" href="#loft-faq-toc"><?php print t('Back to Index') ?></a>
</div><!-- /.loft-faq-category-wrapper -->
