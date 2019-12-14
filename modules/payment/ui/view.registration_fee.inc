<?php
include_once './common/class.common.inc';
include_once 'blade/view.payment.blade.inc';
?>
<div class="panel panel-default">
<div class="panel-heading">Registration Fee </div>
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
	<div class="aa">
		 Term: 
	<input type="text" name="trm" size="5">	<br> <br>
	</div>
<table width="437" class="t1">
	  <tr>
    <th>Description</th>
    <th >Taka</th>
  </tr>
  <tr>
    <td>01. Admission fee</td>
    <td>
      <input type="number" name="af" value= "0">
    </td>
  </tr>

	<tr>
		<td>02. Pay/Pay book</td>
		<td>
			<input type="number" name="pb" value="0">
		</td>
	</tr>

	<tr>
		<td>03. Security(General)</td>
		<td>
			<input type="number" name="scg" value="0">
		</td>
	</tr>

	<tr>
		<td>04. Transportation</td>
		<td>
			<input type="number" name="tp" value="0">
		</td>
	</tr>

	<tr>
		<td>05. Course registration</td>
		<td>
			<input type="number" name="cr" value="0">
		</td>
	</tr>

	<tr>
		<td>06. Verification/Attestation fee</td>
		<td>
			<input type="number" name="vf" value="0">
		</td>
	</tr>

	<tr>
		<td>07. Retake</td>
		<td>
			<input type="number" name="rt" value="0">
		</td>
	</tr>

	<tr>
		<td>08. Re-retake</td>
		<td>
			<input type="number" name="rrt" value="0">
		</td>
	</tr>

	<tr>
		<td>09. BNCC</td>
		<td>
			<input type="number" name="bncc" value="0">
		</td>
	</tr>

	<tr>
		<td>10. Library</td>
		<td>
			<input type="number" name="lb" value="0">
		</td>
	</tr>

	<tr>
		<td>11. Medical/Healthcard</td>
		<td>
			<input type="number" name="med" value="0">
		</td>
	</tr>

	<tr>
		<td>12. Cultural</td>
		<td>
			<input type="number" name="cl" value="0">
		</td>
	</tr>

	<tr>
		<td>13. Religious fee</td>
		<td>
			<input type="number" name="rg" value="0">
		</td>
	</tr>

	<tr>
		<td>14. Examination fee</td>
		<td>
			<input type="number" name="ef" value="0">
		</td>
	</tr>

	<tr>
		<td>15. Session Charge</td>
		<td>
			<input type="number" name="sc" value="0">
		</td>
	</tr>

	<tr>
		<td>16. Gradesheet</td>
		<td>
			<input type="number" name="gs" value="0">
		</td>
	</tr>
	<tr>
		<td>17. Provisional Certificate</td>
		<td>
			<input type="number" name="pc" value="0">
		</td>
	</tr>

	<tr>
		<td>18. Main Certificate</td>
		<td>
			<input type="number" name="mc" value="0">
		</td>
	</tr>

	<tr>
		<td>19. Transcript</td>
		<td>
			<input type="number" name="tsc" value="0">
		</td>
	</tr>

	<tr>
		<td>20. Security(Library)</td>
		<td>
			<input type="number" name="scl" value="0">
		</td>
	</tr>

	<tr>
		<td>21. Equivalence Certificate</td>
		<td>
			<input type="number" name="ec" value="0">
		</td>
	</tr>

	<tr>
		<td>22. Fine(Library)</td>
		<td>
			<input type="number" name="flib" value="0">
		</td>
	</tr>

	<tr>
		<td>23. Fine(Course registration)</td>
		<td>
			<input type="number" name="fcr" value="0">
		</td>
	</tr>

	<tr>
		<td>24. MC/MI Certificate</td>
		<td>
			<input type="number" name="mmc" value="0">
		</td>
	</tr>

	<tr>
		<td>25. MFIL/PHD</td>
		<td>
			<input type="number" name="mfph" value="0">
		</td>
	</tr>

	<tr>
		<td>26. Student Welfare</td>
		<td>
			<input type="number" name="sw" value="0">
		</td>
	</tr>

	<tr>
		<td>27. Sports</td>
		<td>
			<input type="number" name="sp" value="0">
		</td>
	</tr>

	<tr>
		<td>28. Publication</td>
		<td>
			<input type="number" name="pl" value="0">
		</td>
	</tr>

	<tr>
		<td>29. Others</td>
		<td>
			<input type="number" name="ot" value="0">
		</td>
	</tr>
</table>
<br>
	<input id="btn_s" type="submit" value="Pay Fee" name="payr">
</form>
