<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Hall Fee </div>
<div class="panel-body">
<h1 class="hh1"> KHULNA UNIVERSITY </h1>
<h2 class="hh1" id="hh2"> Students Hall Payment Receipt </h2>
<div class="aa">
Name: <?php echo $getROW->getFirstName(); ?>			<br>
Student id: <?php echo $getROW->getUniversityID(); ?><br>
Discipline: <?php echo $getROW->getDiscipline(); ?><br>
<b>Account Balance: <?php echo $balance; ?> </b><br>
</div> 
<form class="f1" method="post">
	<div class="aa">
		 Hall Name: 
	<input type="text" name="hname" size="10">	<br> <br>
</div>
	<div class="aa">
		 Fiscal Year: 
	<input type="text" name="fisy" size="10">	<br> <br>
</div>
<table width="425" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  <tr>
    <td>01. Admission</td>
    <td>
      <input type="number" name="adm" value= "0">
    </td>
  </tr>

	<tr>
		<td>02. Institutional</td>
		<td>
			<input type="number" name="ins" value= "0">
		</td>
	</tr>

	<tr>
		<td>03. Identification Card</td>
		<td>
			<input type="number" name="ic" value= "0">
		</td>
	</tr>

	<tr>
		<td>04. Seat rent</td>
		<td>
			<input type="number" name="sr" value= "0">
		</td>
	</tr>

	<tr>
		<td>05. Utensil</td>
		<td>
			<input type="number" name="ut" value= "0">
		</td>
	</tr>

	<tr>
		<td>06. Common room</td>
		<td>
			<input type="number" name="cr" value= "0">
		</td>
	</tr>

	<tr>
		<td>07. Sports</td>
		<td>
			<input type="number" name="sp" value= "0">
		</td>
	</tr>

	<tr>
		<td>08. Religious Event</td>
		<td>
			<input type="number" name="re" value= "0">
		</td>
	</tr>

	<tr>
		<td>09. Security(Returnable)</td>
		<td>
			<input type="number" name="scr" value= "0">
		</td>
	</tr>

	<tr>
		<td>10. Contingency</td>
		<td>
			<input type="number" name="cgn" value= "0">
		</td>
	</tr>

	<tr>
		<td>11. Hall anniversary</td>
		<td>
			<input type="number" name="ha" value= "0">
		</td>
	</tr>

	<tr>
		<td>12. Fine</td>
		<td>
			<input type="number" name="fn" value= "0">
		</td>
	</tr>

	<tr>
		<td>13. Others</td>
		<td>
			<input type="number" name="ot" value= "0">
		</td>
	</tr>

</table>
<br>

<input id="btn_s" type="submit" value="Pay Fee" name="payh">
</form>
