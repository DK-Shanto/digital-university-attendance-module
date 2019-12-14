<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Others Fee </div>
<div class="panel-body">
<h1 class="hh1"> KHULNA UNIVERSITY </h1>
<h2 class="hh1" id="hh2"> Students Payment Receipt </h2>
<div class="aa">
Name: <?php echo $getROW->getFirstName(); ?>			<br>
Student id: <?php echo $getROW->getUniversityID(); ?><br>
Discipline: <?php echo $getROW->getDiscipline(); ?><br>
<b>Account Balance: <?php echo $balance; ?> </b><br>
</div>    
<form class="f1" method="post">
<table width="650" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  		<td width="570">
			<input type="text" style="height:100px;width: 570px;"  name="desc" value="Description...">
		</td>
		<br>
		<td>
			<input type="text" style="height:100px;" name="amount" value= "0">		<br>
		</td>
</table>
<br>
<input id="btn_s" type="submit" value="Pay Fee" name="payo">
</form>