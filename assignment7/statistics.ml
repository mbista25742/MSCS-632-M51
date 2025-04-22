(* Calculate mean using List.fold_left to sum values *)
let mean numbers =
  if List.length numbers = 0 then 0.0
  else
    let sum = List.fold_left (+) 0 numbers in
    float_of_int sum /. float_of_int (List.length numbers)

(* Calculate median by sorting the list and finding middle element(s) *)
let median numbers =
  let sorted = List.sort compare numbers in
  let len = List.length sorted in
  if len = 0 then 0.0
  else if len mod 2 = 1 then
    (* Odd length - return middle element *)
    float_of_int (List.nth sorted (len / 2))
  else
    (* Even length - average of two middle elements *)
    let mid_right = List.nth sorted (len / 2) in
    let mid_left = List.nth sorted ((len / 2) - 1) in
    float_of_int (mid_left + mid_right) /. 2.0

(* Helper function to count occurrences of each value *)
let count_occurrences lst =
  let rec add_to_counts counts x =
    match counts with
    | [] -> [(x, 1)]
    | (y, c) :: rest when y = x -> (y, c + 1) :: rest
    | pair :: rest -> pair :: add_to_counts rest x
  in
  List.fold_left add_to_counts [] (List.sort compare lst)

(* Calculate mode using higher-order functions *)
let mode numbers =
  if List.length numbers = 0 then ([], 0)
  else
    let counts = count_occurrences numbers in
    let max_count = List.fold_left (fun acc (_, count) -> max acc count) 0 counts in
    if max_count = 1 then
      ([], 0)  (* No mode if all values appear once *)
    else
      let modes = List.filter (fun (_, count) -> count = max_count) counts in
      (List.map fst modes, max_count)

(* Main function to demonstrate the statistics calculations *)
let () =
  print_string "Enter integers separated by spaces: ";
  let input = read_line () in
  let numbers = 
    input
    |> String.split_on_char ' '
    |> List.filter (fun s -> String.length s > 0)
    |> List.map int_of_string
  in
  
  let mean_value = mean numbers in
  let median_value = median numbers in
  let (mode_values, mode_count) = mode numbers in
  
  Printf.printf "\nStatistics:\n";
  Printf.printf "Mean: %.2f\n" mean_value;
  Printf.printf "Median: %.2f\n" median_value;
  
  Printf.printf "Mode: ";
  if mode_count = 0 then
    Printf.printf "No mode (all values appear once)\n"
  else begin
    List.iter (fun x -> Printf.printf "%d " x) mode_values;
    Printf.printf "(appears %d times)\n" mode_count
  end