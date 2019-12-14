<?php
include_once './common/class.common.inc';
include_once  'blade/view.payment_details.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Others Fee </div>
<div class="panel-body">
<h1 class="hh1"> KHULNA UNIVERSITY </h1>
<h2 class="hh1" id="hh2"> Students Payment Receipt </h2>
<div class="aa">
Name: <?php echo $getOthersFee->getName(); ?>			<br>
Student id: <?php echo$getOthersFee->getUniversityID(); ?><br>
Discipline: <?php echo $getOthersFee->getDiscipline(); ?><br>
Date: <?php echo $getOthersFee->getDate(); ?><br>
</div>    
<table width="650" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  		<td height="100">
	<?php echo $getOthersFee->getDescription();?><br>
		</td>
		<br>
		<td height="100">
			<?php echo $getOthersFee->getTotal();?><br>
		</td>
</table>